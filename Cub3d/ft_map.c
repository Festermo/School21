/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:46:20 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:46:21 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_init_map(t_map_values *map, int ld, char **line1)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (get_next_line(ld, line1))
	{
		ft_whatsize(*line1, map);
		j++;
		free(*line1);
	}
	ft_whatsize(*line1, map);
	free(*line1);
	if (!(map->cfg.map = (char **)malloc((j + 2) * sizeof(char *))))
		ft_exitm(map);
	while (i < (j + 2))
	{
		map->cfg.map[i] = NULL;
		i++;
	}
	map->cfg.map[i] = NULL;
	return ;
}

void	ft_map1(t_map_values *map, char *str, int *j, int *i)
{
	while (str[*j] != '\0')
	{
		if (str[*j] == '0' || str[*j] == '1' || str[*j] == '2'
		|| str[*j] == 'N' || str[*j] == 'W' || str[*j] == 'E'
		|| str[*j] == 'S' || str[*j] == ' ')
			map->cfg.map[*i][*j] = str[*j];
		else
		{
			ft_printerror(5);
			ft_free_exit(map);
			exit(0);
			return ;
		}
		*j += 1;
	}
}

void	ft_fill_map(t_map_values *map, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->cfg.map[i] != NULL)
		i++;
	if (!(map->cfg.map[i] = (char *)malloc(sizeof(char) * (map->cfg.size + 1))))
		ft_exitm(map);
	j = 0;
	ft_map1(map, str, &j, &i);
	while (j < (map->cfg.size + 1))
	{
		map->cfg.map[i][j] = '\0';
		j++;
	}
	map->cfg.map[i][j] = '\0';
}

void	ft_exit7(t_map_values *map)
{
	ft_printerror(5);
	ft_free_exit(map);
	exit(0);
}

void	ft_map(char *line, t_map_values *map, int *flag)
{
	int i;

	i = 0;
	if (line[i] == '\0')
	{
		ft_free_exit(map);
		ft_printerror(5);
		exit(0);
	}
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == '1')
		{
			ft_fill_map(map, line);
			*flag = 1;
			return ;
		}
		else
			ft_exit7(map);
	}
	return ;
}
