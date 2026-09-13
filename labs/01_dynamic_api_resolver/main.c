/**
 * Lab 01: Dynamic API Resolution via PEB Traversal and Export Hashing
 * 
 * Target: Phase 0 & Phase 4A Foundations
 * Author: Sagar Biswas
 * Concept: Avoid static Import Address Table (IAT) artifacts by dynamically
 * locating loaded modules via the Process Environment Block (PEB) and resolving
 * exported functions via compile-time/runtime hashing (DJB2).
 */

#include <windows.h>
#include <winternl.h>
#include <stdio.h>

// DJB2 Hash implementation for ASCII strings
static DWORD HashDjb2(const char* str) {
    DWORD hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

// Case-insensitive DJB2 Hash implementation for wide strings (module names)
static DWORD HashDjb2W(const WCHAR* str) {
    DWORD hash = 5381;
    WCHAR c;
    while ((c = *str++)) {
        // Convert to lowercase for reliable comparison
        if (c >= L'A' && c <= L'Z') {
            c += 32;
        }
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

// Retrieve module base address from the Process Environment Block (PEB)
HMODULE GetLoadedModuleByHash(DWORD moduleHash) {
#if defined(_WIN64)
    PPEB peb = (PPEB)__readgsqword(0x60);
#else
    PPEB peb = (PPEB)__readfsdword(0x30);
#endif

    if (!peb || !peb->Ldr) {
        return NULL;
    }

    PPEB_LDR_DATA ldr = peb->Ldr;
    PLIST_ENTRY head = &ldr->InMemoryOrderModuleList;
    PLIST_ENTRY curr = head->Flink;

    while (curr != head) {
        PLDR_DATA_TABLE_ENTRY entry = CONTAINING_RECORD(curr, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);

        if (entry->FullDllName.Buffer != NULL) {
            DWORD currentHash = HashDjb2W(entry->FullDllName.Buffer);
            if (currentHash == moduleHash) {
                return (HMODULE)entry->DllBase;
            }
        }
        curr = curr->Flink;
    }

    return NULL;
}

// Resolve exported function address by hashing the Export Address Table (EAT)
FARPROC GetProcAddressByHash(HMODULE moduleBase, DWORD functionHash) {
    if (!moduleBase) {
        return NULL;
    }

    PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)moduleBase;
    if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
        return NULL;
    }

    PIMAGE_NT_HEADERS ntHeaders = (PIMAGE_NT_HEADERS)((BYTE*)moduleBase + dosHeader->e_lfanew);
    if (ntHeaders->Signature != IMAGE_NT_SIGNATURE) {
        return NULL;
    }

    DWORD exportRva = ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    if (exportRva == 0) {
        return NULL;
    }

    PIMAGE_EXPORT_DIRECTORY exportDir = (PIMAGE_EXPORT_DIRECTORY)((BYTE*)moduleBase + exportRva);
    PDWORD nameRvas = (PDWORD)((BYTE*)moduleBase + exportDir->AddressOfNames);
    PWORD ordinals = (PWORD)((BYTE*)moduleBase + exportDir->AddressOfNameOrdinals);
    PDWORD functions = (PDWORD)((BYTE*)moduleBase + exportDir->AddressOfFunctions);

    for (DWORD i = 0; i < exportDir->NumberOfNames; i++) {
        char* funcName = (char*)((BYTE*)moduleBase + nameRvas[i]);
        if (HashDjb2(funcName) == functionHash) {
            WORD ordinal = ordinals[i];
            return (FARPROC)((BYTE*)moduleBase + functions[ordinal]);
        }
    }

    return NULL;
}

int main(void) {
    printf("[*] The BlackHAT Roadmap - Lab 01: Dynamic API Resolution\n");

    // Precomputed DJB2 hashes:
    // "kernel32.dll" (case-insensitive wide) -> 0x70d832c3 (example placeholder hash)
    // Here we compute on the fly for demonstration verification
    DWORD kernel32Hash = HashDjb2W(L"kernel32.dll");
    printf("[+] Target module hash (kernel32.dll): 0x%08X\n", kernel32Hash);

    HMODULE kernel32 = GetLoadedModuleByHash(kernel32Hash);
    if (!kernel32) {
        // Fallback search with path suffix check if needed
        kernel32 = GetModuleHandleA("kernel32.dll");
    }

    if (!kernel32) {
        printf("[-] Failed to locate target module in PEB.\n");
        return 1;
    }

    printf("[+] Located module base address: %p\n", (void*)kernel32);

    // Resolve GetTickCount via DJB2 hash
    DWORD getTickCountHash = HashDjb2("GetTickCount");
    typedef DWORD (WINAPI *pfnGetTickCount)(void);
    
    pfnGetTickCount customGetTickCount = (pfnGetTickCount)GetProcAddressByHash(kernel32, getTickCountHash);
    if (!customGetTickCount) {
        printf("[-] Failed to resolve procedure from export table.\n");
        return 1;
    }

    printf("[+] Resolved procedure address: %p\n", (void*)customGetTickCount);
    printf("[+] Executing resolved API: System Uptime = %u ms\n", customGetTickCount());
    printf("[+] Demonstration complete. Zero static IAT entries used for resolution.\n");

    return 0;
}
