/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:47:17 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:47:19 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_exit2(t_map_values *map)
{
	ft_printerror(4);
	ft_free_exit(map);
	exit(0);
}

void	ft_skip_so(t_map_values *map, char *str, int i, int j)
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
			if (!(map->cfg.so_tex = (char *)malloc(sizeof(char) * (j + 1))))
				ft_exitm(map);
			i = tmp;
			ft_skip22(&i, &j, str, map);
			map->cfg.so_tex[j] = '\0';
			flag = 1;
		}
		else
			ft_exit2(map);
	}
}

void	ft_fill_sotext(t_map_values *map, char *str, int i, int j)
{
	ft_skip_so(map, str, i, j);
}
