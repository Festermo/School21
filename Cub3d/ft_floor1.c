/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:45:16 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 14:28:52 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_exit6(t_map_values *map)
{
	ft_printerror(1);
	ft_free_exit(map);
	exit(0);
}

void	ft_floor_red(char *str, int *i, t_map_values *map, int *flag)
{
	int j;

	j = 0;
	map->cfg.flagrf = 1;
	while (ft_isdigit(str[*i]))
	{
		map->cfg.floor_red = map->cfg.floor_red * 10 + (str[*i] - '0');
		*i += 1;
		j++;
	}
	if (j > 3)
		ft_exit6(map);
	*flag = 1;
}

void	ft_floor_green(char *str, int *i, t_map_values *map, int *flag)
{
	int j;

	j = 0;
	map->cfg.flaggf = 1;
	while (ft_isdigit(str[*i]))
	{
		map->cfg.floor_green = map->cfg.floor_green * 10 + (str[*i] - '0');
		*i += 1;
		j++;
	}
	if (j > 3)
		ft_exit6(map);
	*flag = 2;
}

void	ft_floor_blue(char *str, int *i, t_map_values *map, int *flag)
{
	int j;

	j = 0;
	map->cfg.flagbf = 1;
	while (ft_isdigit(str[*i]))
	{
		map->cfg.floor_blue = map->cfg.floor_blue * 10 + (str[*i] - '0');
		*i += 1;
		j++;
	}
	if (j > 3)
		ft_exit6(map);
	*flag = 3;
}
