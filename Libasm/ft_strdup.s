section .text

global _ft_strdup
extern _ft_strlen
extern _ft_strcpy
extern _malloc

_ft_strdup:
            call _ft_strlen
            inc rax
            push rdi
            mov rdi, rax
            call _malloc
            pop r8
            cmp rax, 0
            jz  errno
            mov rdi, rax
            mov rsi, r8
            call _ft_strcpy
            ret
errno:
            mov rax, 0
            ret