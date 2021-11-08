section .text

global _ft_strlen

_ft_strlen:
                mov rax, 0
                jmp start
start:
                cmp byte[rdi + rax], 0
                je  end
                inc rax
                jmp start
end:
                ret