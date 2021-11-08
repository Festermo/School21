/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:45:07 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:45:09 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_floor1(t_map_values *map, char *str, int i, int j)
{
	int flag;

	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == ',')
		{
			j++;
			i++;
		}
		else if ((ft_isdigit(str[i])) && flag == 0)
			ft_floor_red(str, &i, map, &flag);
		else if ((ft_isdigit(str[i])) && flag == 1)
			ft_floor_green(str, &i, map, &flag);
		else if ((ft_isdigit(str[i])) && flag == 2)
			ft_floor_blue(str, &i, map, &flag);
		else
			ft_exit6(map);
	}
	return (j);
}

void	ft_fill_floor(t_map_values *map, char *str)
{
	int i;
	int j;

	i = 1;
	j = 0;
	j = ft_floor1(map, str, i, j);
	if (j > 2)
		ft_exit6(map);
	return ;
}

void	ft_floor(char *line, t_map_values *map)
{
	int i;

	i = 0;
	map->cfg.flag = 1;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == 'F')
		{
			ft_fill_floor(map, line + i);
			return ;
		}
		else
		{
			ft_printerror(1);
			ft_free_exit(map);
			exit(0);
		}
	}
	return ;
}
