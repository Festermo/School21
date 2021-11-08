/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:46:27 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:46:29 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
	return (0);
}

void	ft_exit3(t_map_values *map)
{
	ft_printerror(4);
	ft_free_exit(map);
	exit(0);
}

void	ft_skip_no(t_map_values *map, char *str, int i, int j)
{
	int tmp;
	int flag;

	tmp = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] != ' ' && flag == 0)
		{
			tmp = i;
			ft_skip(str, &i, &j);
			if (!(map->cfg.no_tex = (char *)malloc(sizeof(char) * (j + 1))))
				ft_exitm(map);
			i = tmp;
			ft_skip2(&i, &j, str, map);
			map->cfg.no_tex[j] = '\0';
			flag = 1;
		}
		else
			ft_exit3(map);
	}
}

void	ft_fill_notext(t_map_values *map, char *str, int i, int j)
{
	ft_skip_no(map, str, i, j);
	return ;
}
