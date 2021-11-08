# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: festermo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 13:59:06 by festermo          #+#    #+#              #
#    Updated: 2020/06/24 13:59:24 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c ft_atoi.c ft_itoa_hexes.c ft_itoa.c ft_print_hex_low.c ft_print_hex_up.c ft_print_ptr.c ft_print_unsigned.c ft_printchar.c ft_printnbr.c ft_printstr.c ft_putchar_fd.c ft_putnbr_fd.c ft_putnbrs.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strrchr.c ft_which_param.c ft_print_hex_low2.c ft_print_unsigned2.c ft_printnbr2.c ft_printnbr3.c ft_printnbr4.c ft_printstr2.c ft_memset.c
OBJ = $(SOURCES:.c=.o)
COMPILER = gcc -c -Wall -Werror -Wextra
HEADER = ./libftprintf.h ./libft.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
		$(COMPILER) $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
