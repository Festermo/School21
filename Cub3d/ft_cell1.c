/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cell1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:43:23 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 14:26:02 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_cell_red(char *str, int *i, t_map_values *map, int *flag)
{
	int j;

	j = 0;
	map->cfg.flagrc = 1;
	while (ft_isdigit(str[*i]))
	{
		map->cfg.cell_red = map->cfg.cell_red * 10 + (str[*i] - '0');
		*i += 1;
		j++;
	}
	if (j > 3)
		ft_exit22(map);
	*flag = 1;
}

void	ft_cell_green(char *str, int *i, t_map_values *map, int *flag)
{
	int j;

	j = 0;
	map->cfg.flaggc = 1;
	while (ft_isdigit(str[*i]))
	{
		map->cfg.cell_green = map->cfg.cell_green * 10 + (str[*i] - '0');
		*i += 1;
		j++;
	}
	if (j > 3)
		ft_exit22(map);
	*flag = 2;
}

void	ft_cell_blue(char *str, int *i, t_map_values *map, int *flag)
{
	int j;

	j = 0;
	map->cfg.flagbc = 1;
	while (ft_isdigit(str[*i]))
	{
		map->cfg.cell_blue = map->cfg.cell_blue * 10 + (str[*i] - '0');
		*i += 1;
		j++;
	}
	if (j > 3)
		ft_exit22(map);
	*flag = 3;
}
