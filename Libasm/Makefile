# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: festermo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 19:22:13 by festermo          #+#    #+#              #
#    Updated: 2020/10/28 19:22:34 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libasm.a
SRC=ft_write.s ft_read.s ft_strlen.s ft_strcmp.s ft_strcpy.s ft_strdup.s
OBJ=$(SRC:.s=.o)
CC = gcc -Wall -Werror -Wextra
NASM = nasm -fmacho64

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.s
	$(NASM) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) libasm

re: fclean all

test: re
	rm -f libasm
	gcc -Wall -Wextra -Werror -L. -lasm main.c -o libasm
	./libasm
