# The BlackHAT Roadmap: Operator Journey Tracker

Fork this repository to track your progress through the curriculum. Check off milestones as you master theoretical concepts, construct operational labs, and implement working code.

---

## Profile & Target Operator Track

- **Operator Handle**: 
- **Primary Track**: [ ] Track A: Exploit Researcher | [ ] Track B: Enterprise Red Team | [ ] Track C: Stealth Implant Dev | [ ] Track D: Hardware/Infra | [ ] Track E: Special Operations
- **Secondary Track**: 
- **Start Date**: 
- **Estimated Completion**: 

---

## Progress Overview

| Phase | Status | Started [date] | Completed [date] |
|:------|:------:|:-------:|:---------:|
| Phase -1: OPSEC & Infrastructure | [ ] | | |
| Phase 0: Low-Level Foundations | [ ] | | |
| Phase 1: Web Application Security | [ ] | | |
| Phase 2: Network & Infrastructure | [ ] | | |
| Phase 3: System & Kernel Exploitation | [ ] | | |
| Phase 4: Specialized Tracks (primary) | [ ] | | |
| Phase 4: Specialized Tracks (secondary) | [ ] | | |
| Phase 4 Mastery Gate | [ ] | | |
| Phase 5: GREATEST | [ ] | | |
| Phase 6: Special Operations | [ ] | | |

---

## Phase -1: OPSEC & Infrastructure
*Hardened operational discipline, compartmentalization, and anonymous infrastructure.*

- [ ] Complete Threat Modeling & Persona Isolation doctrine
- [ ] Configure non-persistent research OS (Tails OS / Whonix Gateway)
- [ ] Implement multi-hop proxy chains with DNS leak prevention
- [ ] Establish anonymous VPS hosting with non-KYC cryptocurrency
- [ ] Set up secure PGP communications and hardware sterilization protocol
- [ ] **Phase -1 Capstone**: Build fully compartmentalized research bastion host without personal attribution

**Parallel Learning Companions:**
- [ ] Read [Long-Term Survival Tactics](../black-bag/BlackHat_Long-Term_Survival_Tactics.md) alongside this phase
- [ ] Read [Philosophy: The BlackHat Mindset](../field-guides/Philosophy_The_BlackHat_Mindset.md) alongside this phase
- [ ] Read [FAQ](../field-guides/FAQ.md) for pacing guidance and common questions

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

**Parallel Learning Companion:**
- [ ] Build your research environment using the [Lab Setup Guide](../field-guides/Lab_Setup_Guide.md)

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

**Parallel Learning Companions:**
- [ ] Cross-reference techniques against the [MITRE ATT&CK Quick Reference](../field-guides/MITRE_ATT%26CK_Quick_Reference.md)
- [ ] Identify tooling requirements from the [Tools Inventory (300+)](../field-guides/Tools_Inventory.md)
- [ ] Supplement with papers and labs from [Resources Aggregated](../field-guides/Resources_Aggregated.md)

---

## Phase 4: Specialized Operator Tracks

**Select your primary and secondary tracks below.** Mastery in at least 2 tracks is required before proceeding to Phase 5.

### Phase 4A: Implant Development
- [ ] Build custom shellcode loaders and reflective DLL injection primitives
- [ ] Implement process injection techniques (process hollowing, APC injection, early bird)
- [ ] Design and implement C2 protocol communication channels
- [ ] **4A Milestone**: Build a functional custom implant loader

### Phase 4B: C2 Operations
- [ ] Achieve operator depth in Sliver and Havoc C2 frameworks
- [ ] Study Cobalt Strike tradecraft at CRTO level
- [ ] Design multi-layered C2 infrastructure with redirectors
- [ ] Implement domain fronting and CDN-based C2 channels
- [ ] **4B Milestone**: Deploy production-grade evasive C2 infrastructure

### Phase 4C: EDR and AV Evasion
- [ ] Implement direct and indirect syscalls to bypass user-mode hooks
- [ ] Build sleep obfuscation using asynchronous timers (SilentMoonwalk, Cronos, Ekko)
- [ ] Execute synthetic call stack spoofing to defeat EDR stack unwinding
- [ ] Weaponize BYOVD attacks against kernel-level EDR components
- [ ] Implement AMSI and ETW bypass techniques
- [ ] **4C Milestone**: Execute shellcode that passes memory scanners and stack inspection

### Phase 4D: Vulnerability Research
- [ ] Construct custom fuzzing harnesses using AFL++, LibFuzzer, or custom QEMU hooks
- [ ] Develop a code auditing methodology for closed-source targets
- [ ] Understand the 0-day discovery and CVE disclosure process
- [ ] Perform closed-source reverse engineering and targeted fuzzing
- [ ] **4D Milestone**: Discover and document a novel vulnerability in open-source software

### Phase 4E: Persistence and Rootkits
- [ ] Develop Windows kernel drivers for offensive operations
- [ ] Implement Direct Kernel Object Manipulation (DKOM) techniques
- [ ] Study UEFI bootkit persistence mechanisms
- [ ] Implement macOS persistence (LaunchAgent, TCC bypass)
- [ ] Build Linux LKM rootkits and understand eBPF tracepoint hooking
- [ ] **4E Milestone**: Build a proof-of-concept kernel-mode persistence mechanism

### Phase 4F: Cloud and AI Attacks
- [ ] Execute cloud provider attack chains (AWS, Azure, GCP)
- [ ] Exploit Entra ID and M365 attack surfaces (PRT theft, Azure Arc abuse)
- [ ] Study AI agent exploitation techniques
- [ ] Implement indirect prompt injection and RAG poisoning attacks
- [ ] **4F Milestone**: Complete an end-to-end cloud or AI-targeted attack chain in a lab

### Phase 4G: Hardware and Embedded
- [ ] Perform JTAG extraction and hardware debugging
- [ ] Reverse engineer firmware from embedded devices
- [ ] Execute CAN bus and automotive protocol attacks
- [ ] Conduct SDR attacks (GPS spoofing, Bluetooth/BLE interception)
- [ ] **4G Milestone**: Extract and analyze firmware from a real embedded device

### Phase 4H: Supply Chain Attacks
- [ ] Map and exploit CI/CD pipeline attack surfaces
- [ ] Execute dependency confusion attacks in a lab environment
- [ ] Compromise build systems and package repository infrastructure
- [ ] Exploit GitHub Actions and similar automation platforms
- [ ] **4H Milestone**: Demonstrate a full supply chain attack chain in a controlled environment

### Phase 4I: Active Directory Depth
- [ ] Master ADCS ESC1 through ESC15 exploitation
- [ ] Exploit Kerberos delegation abuse (constrained, unconstrained, RBCD)
- [ ] Execute forest and domain trust attacks
- [ ] Perform Azure/Entra ID lateral movement from on-prem AD
- [ ] Implement domain persistence techniques (Golden Ticket, Diamond Ticket, AdminSDHolder)
- [ ] **4I Milestone**: Compromise a multi-forest environment through certificate and delegation abuse

### Phase 4 Mastery Gate

> Completion checkpoint: you must have completed at least **1 primary track** and **1 secondary track** from Phase 4 before advancing.

- [ ] Primary track completed: ______
- [ ] Secondary track completed: ______
- [ ] **Gate Passed**: Ready for Phase 5 and/or Phase 6

---

## Phase 5: GREATEST (Top 0.001%)
*Independent vulnerability research, zero-day engineering, and novel offensive weaponization.*

- [ ] Conduct patch diffing on 1-day browser and OS vulnerabilities
- [ ] Construct custom fuzzing harnesses using AFL++, LibFuzzer, or custom QEMU hooks
- [ ] Research and document novel bypasses against modern OS mitigations (HVCI, CET, VBS)
- [ ] Publish original security research or responsible disclosure advisories
- [ ] **Phase 5 Milestone**: Discover, engineer, and responsibly disclose an original vulnerability in commercial or enterprise software

**Parallel Learning Companion:**
- [ ] Read [Final Word](../field-guides/Final_Word.md) for curriculum statistics, researcher attributions, and horizon research directions

---

## Phase 6: Special Operations
*Physical red teaming, covert entry, advanced social engineering, drone reconnaissance, and quantum transition threat modeling.*

> **Note:** Phase 6 runs parallel to Phase 5, not sequentially after it.

- [ ] Master non-destructive entry: pin tumbler lockpicking, bypass tools, impressioning, and bump keys
- [ ] Audit Electronic Access Control (EAC) systems: Wiegand protocol interception, OSDP flaws, and badge cloning (125 kHz / 13.56 MHz RFID/NFC)
- [ ] Execute physical hardware drops: out-of-band cellular network bridges (Hak5 LAN Turtle, Packet Squirrel)
- [ ] Conduct aerial drone reconnaissance: optical guard patrol mapping and thermal HVAC/server room heat profile analysis
- [ ] Build psychological elicitation, vishing pretexts, and multi-tier identity legend architectures
- [ ] Audit Store Now, Decrypt Later (SNDL) and Post-Quantum Cryptography (PQC) hybrid negotiation fallback vulnerabilities
- [ ] Plan and execute simulated red team operations under TIBER-EU / CBEST frameworks with full post-engagement digital footprint sanitization
- [ ] **Phase 6 Milestone**: Execute an end-to-end full-scope adversary simulation linking physical bypass, hardware implant drop, internal domain compromise, and forensic cleanup

**Parallel Learning Companion:**
- [ ] Read [Final Word](../field-guides/Final_Word.md) for horizon research and 2027-2028 threat landscape
