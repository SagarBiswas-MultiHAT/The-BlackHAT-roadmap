# The BlackHAT Roadmap: Operator Journey Tracker

Fork this repository to track your progress through the curriculum. Check off milestones as you master theoretical concepts, construct operational labs, and implement working code.

---

## Profile & Target Operator Track

- **Operator Handle**: 
- **Target Track**: [ ] Track A: Exploit Researcher | [ ] Track B: Enterprise Red Team | [ ] Track C: Stealth Implant Dev | [ ] Track D: Hardware/Infra
- **Start Date**: 
- **Estimated Completion**: 

---

## Phase -1: OPSEC & Infrastructure
*Hardened operational discipline, compartmentalization, and anonymous infrastructure.*

- [ ] Complete Threat Modeling & Persona Isolation doctrine
- [ ] Configure non-persistent research OS (Tails OS / Whonix Gateway)
- [ ] Implement multi-hop proxy chains with DNS leak prevention
- [ ] Establish anonymous VPS hosting with non-KYC cryptocurrency
- [ ] Set up secure PGP communications and hardware sterilization protocol
- [ ] **Phase -1 Capstone**: Build fully compartmentalized research bastion host without personal attribution

---

## Phase 0: Low-Level Foundations
*Computer architecture, x86/x64 assembly, memory layout, and C programming from the metal.*

- [ ] Understand CPU registers (RAX, RBX, RCX, RDX, RSI, RDI, RSP, RBP, RIP)
- [ ] Write 32-bit and 64-bit Assembly programs natively in NASM
- [ ] Master C memory management: pointers, pointer arithmetic, struct alignment, and heap allocation (`malloc`/`free`)
- [ ] Disassemble and reverse engineer C binaries in Ghidra / IDA Free
- [ ] Understand PE/ELF binary structures: DOS header, NT headers, Section headers, Import/Export tables
- [ ] Trace Windows Native API and syscall dispatching (`ntdll.dll` -> kernel dispatch)
- [ ] **Phase 0 Capstone**: Write a custom PE parser in C that dumps sections and exported functions from disk and memory

---

## Phase 1: Web Application Security
*Modern web application architecture, API testing, and complex logic flaws.*

- [ ] Master HTTP/2, WebSockets, and modern authentication (OAuth 2.0, OpenID Connect, SAML)
- [ ] Exploit Server-Side Request Forgery (SSRF) to extract cloud instance metadata (AWS IMDSv2, GCP)
- [ ] Identify and weaponize insecure deserialization across Python, Java, and PHP
- [ ] Detect and exploit race conditions, TOCTOU flaws, and GraphQL injection
- [ ] **Phase 1 Capstone**: Complete PortSwigger Web Security Academy Practitioner tier

---

## Phase 2: Network & Infrastructure
*Network mapping, Active Directory attack paths, and multi-segment pivoting.*

- [ ] Master Active Directory internals: Kerberos tickets (TGT, TGS, PAC), LDAP, RPC, SMB
- [ ] Execute Kerberoasting and AS-REP roasting with hash cracking strategies
- [ ] Audit and exploit Active Directory Certificate Services (ADCS) misconfigurations (ESC1 to ESC8)
- [ ] Execute cross-forest authentication coercion (PetitPotam, DFSCoerce)
- [ ] Configure multi-hop network pivoting via Chisel, Ligolo-ng, and SSH tunneling
- [ ] **Phase 2 Capstone**: Compromise a multi-tier Active Directory forest and achieve Enterprise Admin via certificate abuse

---

## Phase 3: System & Kernel Exploitation
*Memory corruption, mitigation bypasses, shellcoding, and OS kernel internals.*

- [ ] Write custom x86_64 position-independent shellcode (null-free, dynamic API resolution)
- [ ] Defeat ASLR, DEP/NX, and Stack Canaries using Return-Oriented Programming (ROP)
- [ ] Analyze and exploit Windows heap internals (Segment Heap, LFH allocation primitives)
- [ ] Understand Windows Kernel architecture (EPROCESS, Token Stealing, DKOM)
- [ ] Analyze Driver attack surfaces: Arbitrary Read/Write primitives via vulnerable signed drivers (BYOVD)
- [ ] **Phase 3 Capstone**: Write a functional local privilege escalation exploit bypassing DEP and ASLR

---

## Phase 4: Advanced Operator Tradecraft
*Implant engineering, evasive C2 architecture, modern EDR evasion, and cloud pivoting.*

- [ ] Build custom reflective DLL loaders and shellcode injection primitives
- [ ] Implement sleep obfuscation using asynchronous timers and memory protection flips (Ekko / Foliage)
- [ ] Implement synthetic call stack spoofing to defeat EDR call stack unwinding
- [ ] Resolve syscall numbers dynamically and execute indirect syscalls to bypass user-mode hooks
- [ ] Build custom C2 infrastructure using named pipes, HTTP/3, and domain fronting
- [ ] Develop native loaders in Offensive Rust with dynamic API hashing
- [ ] Exploit hybrid cloud architectures: Entra ID Primary Refresh Token (PRT) theft and Azure Arc abuse
- [ ] Understand Linux eBPF rootkit architecture and kernel tracepoint hooking
- [ ] **Phase 4 Capstone**: Build an evasion-capable implant loader that executes shellcode while passing memory scanners and stack inspection

---

## Phase 5: GREATEST (Top 0.001%)
*Independent vulnerability research, zero-day engineering, and novel offensive weaponization.*

- [ ] Conduct patch diffing on 1-day browser and OS vulnerabilities
- [ ] Construct custom fuzzing harnesses using AFL++, LibFuzzer, or custom QEMU hooks
- [ ] Research and document novel bypasses against modern OS mitigations (HVCI, CET, VBS)
- [ ] Publish original security research or responsible disclosure advisories
- [ ] **Phase 5 Milestone**: Discover, engineer, and responsibly disclose an original vulnerability in commercial or enterprise software
