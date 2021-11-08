/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:44:40 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:44:41 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_texture_option1(t_map_values *map)
{
	if (map->start2 >= M_PI_2 && map->start2 <= M_PI_2 * 3)
	{
		map->actadr = map->imgadr.addr4;
		map->actbpp = map->imgadr.bpp4;
		map->actsize_line = map->imgadr.size_line4;
		map->acthe = map->imgadr.height4;
		map->actwid = map->imgadr.width4;
	}
	else
	{
		map->actadr = map->imgadr.addr;
		map->actbpp = map->imgadr.bpp;
		map->actsize_line = map->imgadr.size_line;
		map->acthe = map->imgadr.height;
		map->actwid = map->imgadr.width;
	}
}

void	ft_texture_option2(t_map_values *map)
{
	if (map->start2 >= M_PI)
	{
		map->actadr = map->imgadr.addr3;
		map->actbpp = map->imgadr.bpp3;
		map->actsize_line = map->imgadr.size_line3;
		map->acthe = map->imgadr.height3;
		map->actwid = map->imgadr.width3;
	}
	else
	{
		map->actadr = map->imgadr.addr2;
		map->actbpp = map->imgadr.bpp2;
		map->actsize_line = map->imgadr.size_line2;
		map->acthe = map->imgadr.height2;
		map->actwid = map->imgadr.width2;
	}
}

void	ft_rest(t_map_values *map, int *j)
{
	map->tex_he = (map->cfg.w_he * 20)
	/ (map->range * cos(map->dir - map->start));
	if (map->tex_he > 1000)
		map->tex_he = 1000;
	while (map->cfg.w_he / 2 - map->tex_he >= 0)
	{
		if (map->cfg.w_he / 2 + map->tex_he <= map->cfg.w_he)
			my_pixel_put(map, *j, map->cfg.w_he / 2 + map->tex_he,
			ft_create_rgb(map->cfg.floor_red,
			map->cfg.floor_green, map->cfg.floor_blue));
		if (map->cfg.w_he / 2 - map->tex_he >= 0)
			my_pixel_put(map, *j, map->cfg.w_he / 2 - map->tex_he,
			ft_create_rgb(map->cfg.cell_red, map->cfg.cell_green,
			map->cfg.cell_blue));
		map->tex_he++;
	}
	*j = *j + 1;
	map->range = 0;
	map->start += M_PI / (map->cfg.w_wid * 3 - 1);
}

void	ft_get_some_values(t_map_values *map, int j, char **mapval)
{
	map->end2 = map->end;
	map->x_fl = map->x_pl;
	map->y_fl = map->y_pl;
	ft_get_dists(map, mapval);
	while (map->start2 < 0)
		map->start2 += 2 * M_PI;
	while (map->start2 > M_PI * 2)
		map->start2 -= 2 * M_PI;
	while (map->end2 < 0)
		map->end2 += 2 * M_PI;
	while (map->end2 > M_PI * 2)
		map->end2 -= 2 * M_PI;
	map->depth[j] = sqrt(pow(map->x_fl - map->x_pl, 2)
	+ pow(map->y_fl - map->y_pl, 2));
	map->x_rem = map->x_fl;
	map->y_rem = map->y_fl;
	while (map->x_rem > 1)
		map->x_rem -= 1;
	while (map->y_rem > 1)
		map->y_rem--;
	map->tex_he = (map->cfg.w_he * 20) /
	(map->range * cos(map->dir - map->start));
	if (map->tex_he > 1000)
		map->tex_he = 1000;
	map->rem = map->tex_he + (map->cfg.w_he / 2);
}

void	ft_choose_textures(t_map_values *map, int j)
{
	if (map->y_fl2 - (int)map->y_fl2 < 0.000001)
		ft_texture_option1(map);
	else if (map->x_fl2 - (int)map->x_fl2 < 0.000001)
		ft_texture_option2(map);
	map->step = map->acthe / (map->tex_he * 2);
	while (map->cfg.w_he / 2 - map->tex_he < map->rem)
	{
		map->color = get_pixel_color(map, map->texture_x, map->texture_y);
		if (map->cfg.w_he / 2 - map->tex_he >= 0 && map->cfg.w_he / 2
		- map->tex_he <= map->cfg.w_he)
			my_pixel_put(map, j, map->cfg.w_he / 2 - map->tex_he, map->color);
		map->texture_y += map->step;
		map->tex_he--;
	}
	map->texture_y = 0;
	if (fabs(map->x_rem - (int)(map->x_rem + 0.5)) > fabs(map->y_rem
	- (int)(map->y_rem + 0.5)))
		map->texture_x = map->x_rem * map->actwid;
	else
		map->texture_x = map->y_rem * map->actwid;
}
