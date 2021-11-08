/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:48:37 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:48:40 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct	s_imgadr
{
	void		*img;
	void		*img1;
	void		*img2;
	void		*img3;
	void		*img4;
	void		*img5;
	char		*addr;
	char		*addr1;
	char		*addr2;
	char		*addr3;
	char		*addr4;
	char		*addr5;
	int			bpp;
	int			bpp1;
	int			bpp2;
	int			bpp3;
	int			bpp4;
	int			bpp5;
	int			size_line;
	int			size_line1;
	int			size_line2;
	int			size_line3;
	int			size_line4;
	int			size_line5;
	int			endian;
	int			endian1;
	int			endian2;
	int			endian3;
	int			endian4;
	int			endian5;
	int			width;
	int			width1;
	int			width2;
	int			width3;
	int			width4;
	int			width5;
	int			height;
	int			height1;
	int			height2;
	int			height3;
	int			height4;
	int			height5;
}				t_imgadr;

typedef struct	s_cfg
{
	int			w_wid;
	int			w_he;
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	char		*spr_tex;
	int			floor_red;
	int			floor_green;
	int			floor_blue;
	int			cell_red;
	int			cell_green;
	int			cell_blue;
	char		**map;
	int			size;
	int			flag;
	int			flag1;
	int			flagrf;
	int			flaggf;
	int			flagbf;
	int			flagrc;
	int			flaggc;
	int			flagbc;
}				t_cfg;

typedef struct	s_bmp
{
	int			fd;
	int			flag;
}				t_bmp;

typedef struct	s_sprites
{
	int			**spritearr;
	int			counter;
	int			x_buf;
	int			y_buf;
	double		x;
	double		y;
}				t_sprites;

typedef struct	s_map_values
{
	int			i_spr;
	int			j_spr;
	double		coef;
	double		step;
	double		texture_x;
	double		texture_y;
	double		range;
	double		*depth;
	double		rem;
	double		tex_he;
	int			color;
	double		start;
	double		end;
	double		start2;
	double		end2;
	double		x_fl2;
	double		y_fl2;
	int			acthe;
	int			actwid;
	t_imgadr	imgadr;
	t_cfg		cfg;
	t_bmp		bmp;
	t_sprites	sprites;
	char		*res;
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	char		*spr_tex;
	char		*floor_col;
	char		*ceil_col;
	void		*mlx;
	void		*win;
	double		x_fl;
	double		y_fl;
	double		dir;
	double		x_pl;
	double		y_pl;
	char		*actadr;
	int			actbpp;
	int			actsize_line;
	double		x_rem;
	double		y_rem;
}				t_map_values;

int				ft_cell1(t_map_values *map, char *str, int i, int j);
void			ft_fill_cell(t_map_values *map, char *str);
void			ft_cell(char *line, t_map_values *map);
void			ft_cell_red(char *str, int *i, t_map_values *map, int *flag);
void			ft_cell_green(char *str, int *i, t_map_values *map, int *flag);
void			ft_cell_blue(char *str, int *i, t_map_values *map, int *flag);
void			ft_check_first(t_map_values *map);
void			ft_null1(t_map_values *map, int *i, int *j, int *player);
void			ft_check_null(t_map_values *map, int str);
void			ft_map_ch1(t_map_values *map, int *i, int *j);
void			ft_check_last(char	*mapval, t_map_values *map);
void			ft_map_check(t_map_values *map);
void			ft_check_full1(t_map_values *map);
void			ft_check_full(t_map_values *map);
void			ft_map_init(t_map_values *map);
void			ft_read_file(int fd, char **line, int *flag, t_map_values *map);
void			ft_lets_parse(t_map_values *map, char *argv);
void			ft_fill_text(t_map_values *map, char *str, int k);
void			ft_path(char *line, t_map_values *map);
void			ft_exit1(t_map_values *map);
void			ft_skip_ea(t_map_values *map, char *str, int i, int j);
void			ft_fill_eatext(t_map_values *map, char *str, int i, int j);
int				ft_floor1(t_map_values *map, char *str, int i, int j);
void			ft_fill_floor(t_map_values *map, char *str);
void			ft_floor(char *line, t_map_values *map);
void			ft_exit6(t_map_values *map);
void			ft_floor_red(char *str, int *i, t_map_values *map, int *flag);
void			ft_floor_green(char *str, int *i, t_map_values *map, int *flag);
void			ft_floor_blue(char *str, int *i, t_map_values *map, int *flag);
void			ft_init_map(t_map_values *map, int fd, char **line1);
void			ft_map1(t_map_values *map, char *str, int *j, int *i);
void			ft_fill_map(t_map_values *map, char *str);
void			ft_exit7(t_map_values *map);
void			ft_map(char *line, t_map_values *map, int *flag);
int				ft_isdigit(int ch);
void			ft_exit3(t_map_values *map);
void			ft_skip_no(t_map_values *map, char *str, int i, int j);
void			ft_fill_notext(t_map_values *map, char *str, int i, int j);
void			ft_skip(char *str, int *i, int *j);
void			ft_skip2(int *i, int *j, char *str, t_map_values *map);
void			ft_skip22(int *i, int *j, char *str, t_map_values *map);
void			ft_skip222(int *i, int *j, char *str, t_map_values *map);
void			ft_skip2222(int *i, int *j, char *str, t_map_values *map);
void			ft_exit2(t_map_values *map);
void			ft_skip_so(t_map_values *map, char *str, int i, int j);
void			ft_fill_sotext(t_map_values *map, char *str, int i, int j);
void			ft_exit5(t_map_values *map);
void			ft_skip22222(int *i, int *j, char *str, t_map_values *map);
void			ft_fill_sprite(t_map_values *map, char *str, int i, int j);
void			ft_fill_spritepath(t_map_values *map, char *str);
void			ft_spritepath(char *line, t_map_values *map);
void			ft_exit4(t_map_values *map);
void			ft_skip_we(t_map_values *map, char *str, int i, int j);
void			ft_fill_wetext(t_map_values *map, char *str, int i, int j);
void			ft_fill_window_hei(t_map_values *map, char *str, int *i);
void			ft_fill_window_wid(t_map_values *map, char *str, int *i);
void			ft_fill_window1(t_map_values *map, char *str, int *i,
			int *flag);
void			ft_fill_window(t_map_values *map, char *str);
void			ft_window(char *line, t_map_values *map);
int				get_next_line(int fd, char **line);
char			*ft_strcpy(char *s1, char *s2);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t num, size_t size);
char			*ft_strdup(char *src);
char			*ft_strchr(const char *str, int ch);
int				ft_atoi(const char *str);
void			ft_free_exit(t_map_values *map);
void			ft_printerror(int numer);
int				ft_create_rgb(int r, int g, int b);
void			ft_free_map(t_map_values *map);
void			write_bmp_image(t_map_values *map, int fd);
void			write_bmp_info(t_map_values *map, int fd);
void			ft_bmp(t_map_values *map);
void			ft_sort_sprites(t_map_values *map);
void			my_pixel_put(t_map_values *map, int x, int y, int color);
int				get_pixel_color(t_map_values *map, int x, int y);
void			ft_init_hero(t_map_values *map);
void			ft_get_spr_values(t_map_values *map,
				int counterbuf, double *spr_dir, double *spr_dist);
void			ft_draw_sprites(t_map_values *map, double spr_size,
				double spr_dist, double spr_dir);
void			ft_sprites(t_map_values *map);
void			ft_texture_option1(t_map_values *map);
void			ft_texture_option2(t_map_values *map);
void			ft_rest(t_map_values *map, int *j);
void			ft_choose_textures(t_map_values *map, int j);
void			ft_get_closer(t_map_values *map, char **mapval);
void			ft_get_dists(t_map_values *map, char **mapval);
void			ft_get_some_values(t_map_values *map, int j, char **mapval);
void			ft_init_imgaddr(t_map_values *map);
void			ft_make_map(char **mapval, t_map_values *map);
void			ft_sprite_coord(t_map_values *map, int order);
void			ft_allocsprites(t_map_values *map);
void			ft_count_sprites(t_map_values *map);
int				ft_keys(int key, t_map_values *map);
int				ft_mouse(t_map_values *map);
void			ft_open_win(t_map_values map);
int				ft_argv(char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_check_path(t_map_values *map);
void			ft_exit10(t_map_values *map);
void			ft_get_dir_aplha(t_map_values *map, char alpha);
void			ft_init_imgaddr2(t_map_values *map);
void			ft_get_dists2(t_map_values *map, char **mapval);
void			ft_sprite_pixel_put(t_map_values *map);
void			ft_change_values(t_map_values *map, int i, int j);
int				ft_argv1(char *str);
void			ft_destroy_and_clear(t_map_values *map);
void			ft_move_forward(t_map_values *map, int *buf);
void			ft_move_backward(t_map_values *map, int *buf);
void			ft_move_left(t_map_values *map, int *buf);
void			ft_move_rigth(t_map_values *map, int *buf);
void			ft_check_argc(int argc, t_map_values *map, char **argv);
void			ft_check_screen(int argc, char **argv, t_map_values *map);
char			f(char *line);
char			t(char *line);
void			ft_exit22(t_map_values *map);
void			ft_condition(t_map_values *map, int i, int j);
void			ft_whatsize(char *line, t_map_values *map);
void			ft_razdel(char **line, int *flag, t_map_values *map);
void			ft_free_sprites(t_map_values *map);
void			ft_close_esc(t_map_values *map);
void			ft_exitm(t_map_values *map);

#endif
