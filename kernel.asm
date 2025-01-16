;;kernel.asm

;nasm directive - 32 bit
bits 32 ; 32-bit code
section .text ; code section
    ;multiboot specification
    align 4 ; align to 4 bytes
    dd 0x1BADB002 ; magic number
    dd 0x00 ; flags
    dd - (0x1BADB002 + 0x00) ; checksum

global start ; the entry point of the kernel
extern kmain ; kernel main function -> C function

start:
    cli ; clear interrupts
    mov esp, stack_space ; set stack pointer where esp points to stack_space, the end of the reserved stack
    call kmain ; call kernel main function
    hlt ; halt the CPU

section .bss
resb 8192 ; reserve 8192 bytes (8KB) for stack
stack_space: