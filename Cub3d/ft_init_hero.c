/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_hero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:45:55 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:45:57 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_init_hero(t_map_values *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->cfg.map[i])
	{
		while (map->cfg.map[i][j])
		{
			if (map->cfg.map[i][j] == 'N' || map->cfg.map[i][j] == 'S' ||
			map->cfg.map[i][j] == 'E' || map->cfg.map[i][j] == 'W')
			{
				map->x_pl = i + 0.5;
				map->y_pl = j + 0.5;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
