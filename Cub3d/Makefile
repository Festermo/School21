FLAGS = -Wall -Wextra -Werror 
NAME = cub3D
HEADER = utils.h
SRC = ft_atoi.c ft_cub3d.c ft_choose_text.c ft_ea.c ft_no.c \
ft_skip.c ft_so.c ft_sprite.c ft_we.c ft_window.c  ft_cell.c ft_cell1.c \
ft_floor.c ft_floor1.c get_next_line_utils.c get_next_line.c ft_map.c ft_check_map.c \
ft_check_null.c ft_draw_textures.c ft_draw_textures2.c ft_draw_sprites.c \
ft_bmp.c ft_main_utils.c ft_init_sprites.c ft_hooks.c ft_putchar_fd.c ft_putstr_fd.c \
ft_parse_utils.c ft_init_hero.c ft_sprite_utils.c ft_get_mapval.c ft_hooks2.c ft_check_argc.c

LIB = ./minilibx_macos_sierra/libmlx.a
ARGS = -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./minilibx_macos_sierra
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) $(ARGS)

%.o: %.c
	gcc -c $(FLAGS)$< -o $@

mlx:
	$(MAKE) -C ./minilibx_macos_sierra

clean:
	/bin/rm -f $(OBJ)
	$(MAKE) clean -C ./minilibx_macos_sierra

fclean:	clean
	/bin/rm -f $(NAME)
	/bin/rm -f ./minilibx_macos_sierra/libmlx.a

re: fclean all

.PHONY: all clean fclean re
