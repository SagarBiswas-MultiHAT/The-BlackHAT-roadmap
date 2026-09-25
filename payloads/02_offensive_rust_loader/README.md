# Lab 02: Offensive Rust In-Memory Loader

## Architectural Overview

Modern Endpoint Detection and Response (EDR) agents actively inspect memory regions allocated with `PAGE_EXECUTE_READWRITE` (RWX). Creating an RWX allocation triggers memory scanners and behavioral heuristics immediately.

This lab demonstrates modern payload execution mechanics in Rust:

1. **State Flipping (RW -> RX)**: Allocating as `PAGE_READWRITE`, writing the payload bytes, and transitioning protection to `PAGE_EXECUTE_READ` before dispatching execution.
2. **Binary Hardening**: Utilizing profile configurations in `Cargo.toml` (`opt-level = "z"`, `lto = true`, `panic = "abort"`, `strip = true`) to strip compilation artifacts, symbol tables, and reduce payload size.

## Compilation

Build in release mode using the MSVC toolchain:

```bash
cargo build --release --target x86_64-pc-windows-msvc
```

Output binary:
`target/x86_64-pc-windows-msvc/release/offensive-rust-loader.exe`
