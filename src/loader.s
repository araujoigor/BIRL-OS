global loader                           ; the entry sylbom for ELF

extern cmain                            ; Defines the C program 
                                        ; entry point

KERNEL_STACK_SIZE equ 4096              ; Defines the stack size

MAGIC_NUMBER equ 0x1BADB002             ; define the magic number constant
FLAGS        equ 0x0                    ; multiboot FLAGS
CHECKSUM     equ -(MAGIC_NUMBER + FLAGS); calculate the CHECKSUM
                                        ; (magic number + checksum + flags = 0)
                                       
section .bss
align 4
kernel_stack:
    resb KERNEL_STACK_SIZE;

section .text                           ; start of the code section
align 4                                 ; sets the memory alignment
    dd MAGIC_NUMBER                     ; writes the magic number,
    dd FLAGS                            ; the FLAGS
    dd CHECKSUM                         ; and the CHECKSUM

loader:                                 ; defines the 'loader' label
    mov esp, kernel_stack + KERNEL_STACK_SIZE
        
    cmp eax, 0x2BADB002                 ; verifies if grub gave us the 
                                        ; correct value on the EAX register,
                                        ; according to the multiboot spec
    jne .error                          ; if the val is wrong, error.

.success:    
    mov eax, 0xCAFEBABE                 ; move a success constant to the EAX reg
    call cmain
.error:
    mov eax, 0xDEADBEEF                 ; move a error constant to the EAX reg

.loop:                                  ; defines the 'loop' label
    jmp .loop                           ; endless loop