/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:47:53 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 14:18:29 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_fill_window_hei(t_map_values *map, char *str, int *i)
{
	int j;

	j = 0;
	while (ft_isdigit(str[*i]))
	{
		map->cfg.w_he = map->cfg.w_he * 10 + (str[*i] - '0');
		*i += 1;
		j++;
	}
	if (j > 4)
		map->cfg.w_he = 1080;
	return ;
}

void	ft_fill_window_wid(t_map_values *map, char *str, int *i)
{
	int j;

	j = 0;
	while (ft_isdigit(str[*i]))
	{
		map->cfg.w_wid = map->cfg.w_wid * 10 + (str[*i] - '0');
		*i += 1;
		j++;
	}
	if (j > 4)
		map->cfg.w_wid = 1920;
	return ;
}

void	ft_fill_window1(t_map_values *map, char *str, int *i, int *flag)
{
	while (str[*i] != '\0')
	{
		if (str[*i] == ' ')
			*i += 1;
		else if ((ft_isdigit(str[*i])) && *flag == 0)
		{
			ft_fill_window_wid(map, str, i);
			*flag = 1;
		}
		else if ((ft_isdigit(str[*i])) && *flag == 1)
		{
			ft_fill_window_hei(map, str, i);
			*flag = 2;
		}
		else
		{
			ft_printerror(3);
			ft_free_exit(map);
			exit(0);
			break ;
		}
	}
	return ;
}

void	ft_fill_window(t_map_values *map, char *str)
{
	int flag;
	int i;

	i = 1;
	flag = 0;
	ft_fill_window1(map, str, &i, &flag);
	return ;
}

void	ft_window(char *line, t_map_values *map)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == 'R')
		{
			ft_fill_window(map, line + i);
			return ;
		}
		else
		{
			ft_printerror(3);
			ft_free_exit(map);
			exit(0);
			break ;
		}
	}
	return ;
}
