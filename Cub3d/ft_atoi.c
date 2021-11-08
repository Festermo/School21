/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:39:34 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:39:41 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_atoi(const char *str)
{
	int		j;
	long	numb;
	int		sgn;

	if (!str)
		return (0);
	j = 0;
	numb = 0;
	sgn = 1;
	while (str[j] == '\v' || str[j] == '\t' || str[j] == '\n'
	|| str[j] == '\f' || str[j] == '\r' || str[j] == ' ')
		j++;
	if (str[j] == '-' || str[j] == '+')
		if (str[j++] == '-')
			sgn = -1;
	while (str[j] >= '0' && str[j] <= '9')
	{
		if (numb > (numb * 10 + (str[j] - '0')))
			return (sgn > 0 ? -1 : 0);
		numb = (numb * 10) + (str[j++] - '0');
	}
	return ((int)(numb * sgn));
}

char	f(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			i++;
			continue ;
		}
		break ;
	}
	return (line[i]);
}

char	t(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			i++;
			continue ;
		}
		break ;
	}
	i++;
	return (line[i]);
}

void	ft_exit22(t_map_values *map)
{
	ft_printerror(2);
	ft_free_exit(map);
	exit(0);
}

void	ft_condition(t_map_values *map, int i, int j)
{
	if (map->cfg.map[i - 1][j] == '\0'
	|| map->cfg.map[i + 1][j] == '\0'
	|| map->cfg.map[i - 1][j] == ' '
	|| map->cfg.map[i + 1][j] == ' '
	|| map->cfg.map[i + 1][j + 1] == ' '
	|| map->cfg.map[i + 1][j - 1] == ' '
	|| map->cfg.map[i - 1][j + 1] == ' '
	|| map->cfg.map[i - 1][j - 1] == ' '
	|| map->cfg.map[i + 1][j + 1] == '\0'
	|| map->cfg.map[i - 1][j + 1] == '\0')
		ft_exit7(map);
}
