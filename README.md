# kernel-x86
Kernel for x86 architecture - Based on Build Your Own X

## Build
```bash
nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -c kernel.c -o kc.o
ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o
```

### Explanation
- `nasm -f elf32 kernel.asm -o kasm.o` - Assemble the kernel.asm file into an object file called kasm.o in ELF32 format
- `gcc -m32 -c kernel.c -o kc.o` - Compile the kernel.c file into an object file called kc.o in 32-bit mode
- `ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o` - Link the object files into a binary file called kernel using the link.ld linker script

The resulting kernel binary can be run using an x86 emulator like QEMU. For example:
```bash
qemu-system-i386 -kernel kernel-<version>
```
