FLAGS = -Wall -Wextra -Werror 
NAME = philo_two
HEADER = philo_two.h
SRC = main.c ft_strlen.c ft_strlcpy.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_itoa.c ft_atoi.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) $(ARGS)

%.o: %.c
	gcc -c $(FLAGS)$< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean:	clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
