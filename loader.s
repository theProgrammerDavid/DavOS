global loader ; the entry symbol for ELF
global outb

MAGIC_NUMBER equ 0x1BADB002
FLAGS equ 0x0
CHECKSUM equ -MAGIC_NUMBER
KERNEL_STACK_SIZE equ 4096

extern sum_of_three
extern kmain
section .text:

align 4
dd MAGIC_NUMBER
dd FLAGS
dd CHECKSUM

outb:
    mov al, [esp+8]
    mov dx, [esp+4]
    out dx, al
    ret

loader:
 ; mov [0x000B8000], dword 0x2841
 ; mov eax, 0xcafebabe		;
 mov esp, kernel_stack + KERNEL_STACK_SIZE
 call kmain
;  push dword 1 
;  push dword 2
;  push dword 3
;  call sum_of_three
;  mov ecx, eax

.loop:
 jmp .loop

section .bss
align 4
kernel_stack:
 resb KERNEL_STACK_SIZE
