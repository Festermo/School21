section .text

global _ft_strcpy

_ft_strcpy:
            push rbx
            mov rax, 0
            jmp start
start:
            mov bl, byte[rsi + rax]
            mov byte[rdi + rax], bl
            cmp byte[rsi + rax], 0
            je  end
            inc rax
            jmp start
end:
            mov rax, rdi
            pop rbx
            ret