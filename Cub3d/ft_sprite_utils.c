/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:47:25 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:47:26 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_sort_sprites(t_map_values *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->sprites.counter)
	{
		j = i + 1;
		while (j < map->sprites.counter)
		{
			ft_change_values(map, i, j);
			j++;
		}
		i++;
	}
}

void	ft_change_values(t_map_values *map, int i, int j)
{
	int bufx;
	int bufy;

	if (sqrt(pow(map->x_pl - map->sprites.spritearr[i][0], 2) +
	pow(map->y_pl - map->sprites.spritearr[i][1], 2)) <
	sqrt(pow(map->x_pl - map->sprites.spritearr[j][0], 2) +
	pow(map->y_pl - map->sprites.spritearr[j][1], 2)))
	{
		bufx = map->sprites.spritearr[i][0];
		bufy = map->sprites.spritearr[i][1];
		map->sprites.spritearr[i][0] = map->sprites.spritearr[j][0];
		map->sprites.spritearr[i][1] = map->sprites.spritearr[j][1];
		map->sprites.spritearr[j][0] = bufx;
		map->sprites.spritearr[j][1] = bufy;
	}
}

void	ft_free_sprites(t_map_values *map)
{
	int i;

	i = 0;
	if (map->sprites.spritearr)
	{
		while (map->sprites.counter > 0)
		{
			free(map->sprites.spritearr[map->sprites.counter - 1]);
			map->sprites.counter--;
		}
		free(map->sprites.spritearr);
	}
}

void	ft_exitm(t_map_values *map)
{
	ft_printerror(7);
	ft_free_exit(map);
	exit(0);
}
