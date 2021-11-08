/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:43:44 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:43:45 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_null1(t_map_values *map, int *i, int *j, int *player)
{
	while (map->cfg.map[*i][*j] != '\0')
	{
		if (map->cfg.map[*i][*j] == '0' || map->cfg.map[*i][*j] == 'N'
		|| map->cfg.map[*i][*j] == 'W' || map->cfg.map[*i][*j] == 'E'
		|| map->cfg.map[*i][*j] == 'S' || map->cfg.map[*i][*j] == '2')
			ft_condition(map, *i, *j);
		if (map->cfg.map[*i][*j] == 'N' || map->cfg.map[*i][*j] == 'W'
		|| map->cfg.map[*i][*j] == 'E' || map->cfg.map[*i][*j] == 'S')
		{
			*player += 1;
			ft_get_dir_aplha(map, map->cfg.map[*i][*j]);
		}
		*j += 1;
	}
}

void	ft_check_null(t_map_values *map, int str)
{
	int i;
	int j;
	int player;

	i = 1;
	j = 0;
	player = 0;
	while (i <= (str - 2))
	{
		ft_null1(map, &i, &j, &player);
		j = 0;
		i++;
	}
	if (player != 1)
		ft_exit7(map);
}

void	ft_map_ch1(t_map_values *map, int *i, int *j)
{
	while (map->cfg.map[*i][*j] != '\0')
	{
		if (map->cfg.map[*i][*j] == ' ')
			*j += 1;
		else if (map->cfg.map[*i][*j] == '1')
		{
			while (map->cfg.map[*i][*j] != '\0' && map->cfg.map[*i][*j] != ' ')
				*j += 1;
			if (map->cfg.map[*i][*j - 1] != '1')
				ft_exit7(map);
		}
		else
			ft_exit7(map);
	}
}

void	ft_check_last(char *mapval, t_map_values *map)
{
	int i;

	i = 0;
	while (mapval[i] != '\0')
	{
		if (mapval[i] != '1' && mapval[i] != ' ')
		{
			ft_printerror(5);
			ft_free_exit(map);
			exit(0);
		}
		i++;
	}
}

void	ft_map_check(t_map_values *map)
{
	int i;
	int j;

	i = 1;
	j = 0;
	ft_check_first(map);
	while (map->cfg.map[i] != NULL)
	{
		ft_map_ch1(map, &i, &j);
		j = 0;
		i++;
	}
	ft_check_null(map, i);
	ft_check_last(map->cfg.map[i - 1], map);
	return ;
}
