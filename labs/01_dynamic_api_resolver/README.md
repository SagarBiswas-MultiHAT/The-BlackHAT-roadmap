# Lab 01: Dynamic API Resolution via PEB Traversal & Export Hashing

## Architectural Overview

Standard Windows executables declare their dependencies in the Import Address Table (IAT). Security software, static signature engines, and EDR agents inspect the IAT during file ingestion to score suspicious capability indicators (e.g., imports of `VirtualAlloc`, `WriteProcessMemory`, `CreateRemoteThread`).

This lab demonstrates how an operator decouples capability execution from the static IAT:

1. **Process Environment Block (PEB) Traversal**: Direct memory access to `GS:[0x60]` (on x64) to locate the loaded module list (`InLoadOrderModuleList` / `InMemoryOrderModuleList`) without calling `GetModuleHandle`.
2. **Export Address Table (EAT) Parsing**: Parsing the target DLL's DOS header, NT headers, and Optional Header Data Directory to inspect export symbol RVAs directly.
3. **DJB2 Hash Comparison**: Comparing precomputed hash values against function names rather than storing cleartext strings in the `.rdata` section.

## Compilation

Using MinGW-w64 on Linux or Windows:

```bash
x86_64-w64-mingw32-gcc -Wall -O2 -s -o resolver.exe main.c
```

Or with Microsoft Visual C++ (`cl.exe`):

```cmd
cl.exe /O2 /W3 main.c
```
