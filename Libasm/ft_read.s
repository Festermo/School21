section .text

extern ___error

global _ft_read

_ft_read:
        mov rax, 0x02000003
        syscall
        jc errno
        ret
errno:
        push rax
        call ___error
        pop rdx
        mov [rax], rdx
        mov rax, -1
        ret