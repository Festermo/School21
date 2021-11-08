/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ea.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:44:57 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:44:59 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_exit1(t_map_values *map)
{
	ft_printerror(4);
	ft_free_exit(map);
	exit(0);
}

void	ft_skip_ea(t_map_values *map, char *str, int i, int j)
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
			if (!(map->cfg.ea_tex = (char *)malloc(sizeof(char) * (j + 1))))
				ft_exitm(map);
			i = tmp;
			ft_skip2222(&i, &j, str, map);
			map->cfg.ea_tex[j] = '\0';
			flag = 1;
		}
		else
			ft_exit1(map);
	}
}

void	ft_fill_eatext(t_map_values *map, char *str, int i, int j)
{
	ft_skip_ea(map, str, i, j);
}
