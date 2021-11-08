/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:44:18 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:44:20 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_make_map(char **mapval, t_map_values *map)
{
	int j;
	int counterbuf;

	j = 0;
	counterbuf = 0;
	ft_init_imgaddr(map);
	ft_sort_sprites(map);
	while (map->start < map->end)
	{
		map->start2 = map->start;
		ft_get_some_values(map, j, mapval);
		ft_choose_textures(map, j);
		ft_rest(map, &j);
	}
	ft_sprites(map);
	counterbuf = map->sprites.counter;
	while (counterbuf-- > 0)
		map->sprites.spritearr[counterbuf][2] = 0;
	if (map->bmp.flag == 2)
	{
		map->bmp.flag = 1;
		ft_bmp(map);
	}
	mlx_put_image_to_window(map->mlx, map->win, map->imgadr.img1, 0, 0);
	free(map->depth);
}

void	ft_open_win(t_map_values map)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	if (map.bmp.flag != 2)
		win = mlx_new_window(mlx, map.cfg.w_wid,
	map.cfg.w_he, "cub3D");
	else
		win = NULL;
	map.mlx = mlx;
	map.win = win;
	ft_make_map(map.cfg.map, &map);
	mlx_hook(map.win, 2, (1L << 0), ft_keys, &map);
	mlx_hook(map.win, 17, 0L, ft_mouse, &map);
	mlx_loop(mlx);
}

int		main(int argc, char **argv)
{
	char			*line;
	int				i;
	int				j;
	t_map_values	map;

	i = 0;
	j = 0;
	line = NULL;
	ft_map_init(&map);
	ft_check_argc(argc, &map, argv);
	ft_check_screen(argc, argv, &map);
	ft_count_sprites(&map);
	ft_allocsprites(&map);
	ft_init_hero(&map);
	ft_open_win(map);
	return (0);
}
