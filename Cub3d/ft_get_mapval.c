/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mapval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:45:25 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:45:27 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_get_dir_aplha(t_map_values *map, char alpha)
{
	if (alpha == 'N')
		map->dir = M_PI_2 * 3;
	else if (alpha == 'S')
		map->dir = M_PI_2;
	else if (alpha == 'E')
		map->dir = 0;
	else if (alpha == 'W')
		map->dir = M_PI;
}

void	ft_check_first(t_map_values *map)
{
	int i;

	i = 0;
	while (map->cfg.map[0][i] != '\0')
	{
		if (map->cfg.map[0][i] != '1' && map->cfg.map[0][i] != ' ')
		{
			ft_printerror(5);
			ft_free_exit(map);
			exit(0);
			return ;
		}
		i++;
	}
}
