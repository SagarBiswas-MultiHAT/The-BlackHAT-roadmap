# Offensive Engineering Payloads

## Operational Overview

This directory houses ready-to-compile, weaponized source implementations designed for low-level research, authorized red team operations, and defensive telemetry verification.

Rather than relying on public automated tools that trigger static signatures, these codebases demonstrate primitive engineering from first principles: direct Native API dispatching, memory protection state flips, and Process Environment Block (PEB) traversal.

---

## Payload Index

| Identifier | Focus | Language | Key Mechanics |
| :---: | :--- | :---: | :--- |
| **[01_dynamic_api_resolver](01_dynamic_api_resolver/)** | In-Memory Dynamic API Resolution | C | PEB traversal via `GS:[0x60]`, EAT parsing, DJB2 function hashing, decoupling from static IAT |
| **[02_offensive_rust_loader](02_offensive_rust_loader/)** | EDR-Evading Memory Loader | Rust | Memory state flipping (`PAGE_READWRITE` to `PAGE_EXECUTE_READ`), zero RWX allocation flags, binary stripping |

---

## Infrastructure & Lab Prerequisites

> 📖 **Virtualization & Range Setup**:  
> For full hypervisor architecture (Proxmox / ESXi), multi-tier Active Directory topologies (GOAD), and isolated malware analysis sandboxes (FlareVM / REMnux), refer to the **[Lab Setup Guide](../field-guides/Lab_Setup_Guide.md)**.

### Toolchain Requirements

- **C / C++ Toolchains**:
  - Linux/WSL cross-compilation: `x86_64-w64-mingw32-gcc` (MinGW-w64)
  - Windows native: Microsoft Visual C++ Build Tools (`cl.exe`) or Clang/LLVM
- **Rust Toolchains**:
  - `rustup` with target `x86_64-pc-windows-msvc`
  - Cargo profile optimizations (`opt-level = "z"`, `lto = true`, `strip = true`)

---

## Legal & Safety Notice

All payload code is strictly for authorized educational research and explicit penetration testing engagements. Test only inside isolated virtualized sandboxes.
