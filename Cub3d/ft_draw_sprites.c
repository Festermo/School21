/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:44:28 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/23 15:43:32 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_sprite_pixel_put(t_map_values *map)
{
	if (map->i_spr * map->coef >= 0 && map->i_spr * map->coef
	<= map->actwid && map->j_spr * map->coef >= 0
	&& map->j_spr * map->coef <= map->acthe)
		map->color = get_pixel_color(map, map->i_spr *
		map->coef, map->j_spr * map->coef);
	if (map->color > 0 && map->sprites.x + map->i_spr <=
	map->cfg.w_wid && map->sprites.x + map->i_spr >= 0
	&& map->sprites.y + map->j_spr <= map->cfg.w_he &&
	map->sprites.y + map->j_spr >= 0)
		my_pixel_put(map, map->sprites.x + map->i_spr,
		map->sprites.y + map->j_spr, map->color);
}

void	ft_get_spr_values(t_map_values *map, int counterbuf, double *spr_dir,
		double *spr_dist)
{
	*spr_dir = atan2(map->sprites.spritearr[counterbuf][0] - map->x_pl + 0.5,
	map->sprites.spritearr[counterbuf][1] + 0.5 - map->y_pl);
	while (*spr_dir - map->dir > M_PI)
		*spr_dir -= 2 * M_PI;
	while (*spr_dir - map->dir < -M_PI)
		*spr_dir += 2 * M_PI;
	*spr_dist = sqrt(pow(map->x_pl - 0.5 -
	map->sprites.spritearr[counterbuf][0], 2) + pow(map->y_pl -
	0.5 - map->sprites.spritearr[counterbuf][1], 2));
}

void	ft_draw_sprites(t_map_values *map, double spr_size,
		double spr_dist, double spr_dir)
{
	spr_size = (int)(map->cfg.w_he / spr_dist);
	map->sprites.x = (spr_dir - map->dir) * map->cfg.w_wid / (M_PI / 3) +
	map->cfg.w_wid / 2 - spr_size / 2;
	map->sprites.y = (map->cfg.w_he / 2) - (spr_size / 2);
	map->coef = map->actwid / (double)spr_size;
	while (++map->i_spr < spr_size)
	{
		map->j_spr = -1;
		if ((map->sprites.x + map->i_spr) <= 0)
			continue;
		if (map->depth[(int)(map->sprites.x) + map->i_spr] < spr_dist)
			continue;
		while (++map->j_spr < spr_size)
		{
			if (map->sprites.y + map->j_spr < 0)
				continue;
			ft_sprite_pixel_put(map);
		}
	}
}

void	ft_sprites(t_map_values *map)
{
	int		counterbuf;
	double	spr_dir;
	double	spr_dist;
	double	spr_size;

	counterbuf = 0;
	spr_size = 0.0;
	map->actadr = map->imgadr.addr5;
	map->actbpp = map->imgadr.bpp5;
	map->actsize_line = map->imgadr.size_line5;
	map->actwid = map->imgadr.width5;
	map->acthe = map->imgadr.height5;
	while (counterbuf < map->sprites.counter)
	{
		map->j_spr = 0;
		map->i_spr = -1;
		if (map->sprites.spritearr[counterbuf][2] == 1)
		{
			ft_get_spr_values(map, counterbuf, &spr_dir, &spr_dist);
			ft_draw_sprites(map, spr_size, spr_dist, spr_dir);
		}
		counterbuf++;
	}
}
