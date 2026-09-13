# Contributing to The BlackHAT Roadmap

Thank you for your interest in contributing to The BlackHAT Roadmap. This repository maintains a high technical bar, focusing on deep, low-level engineering rather than surface-level tool tutorials.

---

## What We Welcome

- **In-Depth Technical Modules**: Comprehensive breakdowns of emerging tradecraft (e.g., hypervisor evasion, advanced ADCS coercion, eBPF rootkit mechanics, hardware bus exploitation).
- **Practical Code Samples**: Clean, compilable, well-documented C, Rust, Assembly, or Python proof-of-concepts targeting the [labs/](../labs/) directory.
- **Curriculum Corrections**: Fixes for dead external links, outdated API signatures, or factual technical discrepancies.
- **Lab Architectures**: Automated deployment scripts (Terraform, Docker Compose, Vagrant) for reproducible research environments.

---

## What We Do Not Accept

- Low-effort aggregations or generic lists of public automated scanners (e.g., standard Nmap or Metasploit cheat sheets).
- Incomplete or non-functional code snippets copied without technical context.
- Marketing links, commercial tool promotions, or referral redirects.

---

## Contribution Guidelines

1. **Keep Explanations Rooted in First Principles**: Explain the underlying system mechanisms (PE headers, memory protection, kernel structures, network protocols) before showing attack implementations.
2. **Code Standards**:
   - C/C++ code must compile cleanly with `gcc`, `clang`, or `cl.exe`.
   - Rust code must format via `cargo fmt` and build cleanly with `cargo build --release`.
   - Provide clear compilation flags and target architecture notes (x86_64, ARM64).
3. **Punctuation and Formatting**:
   - Use standard punctuation (hyphens, commas, colons, periods). Do not use em-dashes in documentation or comments.
   - Maintain GitHub Flavored Markdown standards.
4. **Submitting a Pull Request**:
   - Fork the repository and create a descriptive feature branch (`git checkout -b feature/kernel-module`).
   - Open a pull request using the provided PR template.
   - Summarize the specific technical enhancements and verification steps performed.
