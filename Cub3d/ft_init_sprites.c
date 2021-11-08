/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:46:03 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:46:05 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_sprite_coord(t_map_values *map, int order)
{
	int j;
	int i;
	int k;

	k = 0;
	i = 0;
	j = 0;
	while (map->cfg.map[(int)i])
	{
		while (map->cfg.map[(int)i][(int)j])
		{
			if (map->cfg.map[(int)i][(int)j] == '2')
			{
				if (k == order)
				{
					map->sprites.x_buf = i;
					map->sprites.y_buf = j;
				}
				k++;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_allocsprites(t_map_values *map)
{
	int i;
	int j;

	j = 0;
	i = map->sprites.counter;
	if (!(map->sprites.spritearr = (int **)malloc(i * sizeof(int *))))
		ft_exit2(map);
	while (i-- > 0)
	{
		if (!(map->sprites.spritearr[j] = (int *)malloc(3 * sizeof(int))))
			ft_exit2(map);
		ft_sprite_coord(map, j);
		map->sprites.spritearr[j][0] = map->sprites.x_buf;
		map->sprites.spritearr[j][1] = map->sprites.y_buf;
		map->sprites.spritearr[j][2] = 0;
		j++;
	}
}

void	ft_count_sprites(t_map_values *map)
{
	int i;
	int j;
	int counter;

	counter = 0;
	i = 0;
	j = 0;
	while (map->cfg.map[i])
	{
		while (map->cfg.map[i][j])
		{
			if (map->cfg.map[i][j] == '2')
				counter++;
			j++;
		}
		i++;
		j = 0;
	}
	map->sprites.counter = counter;
}
