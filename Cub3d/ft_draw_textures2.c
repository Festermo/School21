/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textures2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:44:48 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:44:49 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_get_closer(t_map_values *map, char **mapval)
{
	double delta;

	if (mapval[(int)(map->x_fl)][(int)(map->y_fl)] == '1')
	{
		delta = 0.01;
		if (mapval[(int)(map->x_fl -
		sin(map->start) / 50)][(int)(map->y_fl)] != '1')
			while (delta > 0.000001)
			{
				while (map->x_fl2 - (int)map->x_fl2 - delta > 0)
					map->x_fl2 -= delta;
				delta /= 10;
			}
		delta = 0.01;
		if (mapval[(int)map->x_fl2][(int)(map->y_fl2
		- cos(map->start) / 50)] != '1')
			while (delta > 0.000001)
			{
				while (map->y_fl2 - (int)map->y_fl2 - delta > 0)
					map->y_fl2 -= delta;
				delta /= 10;
			}
	}
}

void	ft_init_imgaddr(t_map_values *map)
{
	map->texture_x = 0;
	map->texture_y = 0;
	map->start = map->dir - (M_PI_2 / 3);
	map->end = map->dir + (M_PI_2 / 3);
	map->imgadr.img1 = mlx_new_image(map->mlx, map->cfg.w_wid, map->cfg.w_he);
	map->imgadr.addr1 = mlx_get_data_addr(map->imgadr.img1,
	&(map->imgadr.bpp1), &(map->imgadr.size_line1), &(map->imgadr.endian1));
	map->imgadr.img = mlx_xpm_file_to_image(map->mlx, map->cfg.ea_tex,
	&(map->imgadr.width), &(map->imgadr.height));
	map->imgadr.img2 = mlx_xpm_file_to_image(map->mlx, map->cfg.so_tex,
	&(map->imgadr.width2), &(map->imgadr.height2));
	ft_init_imgaddr2(map);
}

void	ft_get_dists(t_map_values *map, char **mapval)
{
	int anotherbuf;

	map->range = 0;
	while (mapval[(int)(map->x_fl)][(int)(map->y_fl)] != '1' &&
	ft_strchr("012NEWS", mapval[(int)(map->x_fl)][(int)(map->y_fl)]))
	{
		map->x_fl += sin(map->start) / 50;
		map->y_fl += cos(map->start) / 50;
		if (mapval[(int)(map->x_fl)][(int)(map->y_fl)] == '2' &&
		ft_strchr("012NEWS", mapval[(int)(map->x_fl)][(int)(map->y_fl)]))
		{
			anotherbuf = 0;
			while (anotherbuf < map->sprites.counter)
			{
				if ((int)(map->y_fl) == map->sprites.spritearr[anotherbuf][1]
				&& (int)(map->x_fl) == map->sprites.spritearr[anotherbuf][0])
					map->sprites.spritearr[anotherbuf][2] = 1;
				anotherbuf++;
			}
		}
		ft_get_dists2(map, mapval);
		ft_get_closer(map, mapval);
	}
}

void	ft_init_imgaddr2(t_map_values *map)
{
	map->imgadr.img3 = mlx_xpm_file_to_image(map->mlx, map->cfg.no_tex,
	&(map->imgadr.width3), &(map->imgadr.height3));
	map->imgadr.img4 = mlx_xpm_file_to_image(map->mlx, map->cfg.we_tex,
	&(map->imgadr.width4), &(map->imgadr.height4));
	map->imgadr.img5 = mlx_xpm_file_to_image(map->mlx, map->cfg.spr_tex,
	&(map->imgadr.width5), &(map->imgadr.height5));
	map->imgadr.addr = mlx_get_data_addr(map->imgadr.img, &(map->imgadr.bpp),
	&(map->imgadr.size_line), &(map->imgadr.endian));
	map->imgadr.addr2 = mlx_get_data_addr(map->imgadr.img2, &(map->imgadr.bpp2),
	&(map->imgadr.size_line2), &(map->imgadr.endian2));
	map->imgadr.addr3 = mlx_get_data_addr(map->imgadr.img3, &(map->imgadr.bpp3),
	&(map->imgadr.size_line3), &(map->imgadr.endian3));
	map->imgadr.addr4 = mlx_get_data_addr(map->imgadr.img4, &(map->imgadr.bpp4),
	&(map->imgadr.size_line4), &(map->imgadr.endian4));
	map->imgadr.addr5 = mlx_get_data_addr(map->imgadr.img5, &(map->imgadr.bpp5),
	&(map->imgadr.size_line5), &(map->imgadr.endian5));
	if (!(map->depth = (double*)malloc((map->cfg.w_wid + 1) * sizeof(double))))
		ft_exit2(map);
}

void	ft_get_dists2(t_map_values *map, char **mapval)
{
	if (mapval[(int)(map->x_fl)][(int)(map->y_fl)] != '1' &&
	ft_strchr("012NEWS", mapval[(int)(map->x_fl)][(int)(map->y_fl)]))
		map->range++;
	map->x_fl2 = map->x_fl;
	map->y_fl2 = map->y_fl;
}
