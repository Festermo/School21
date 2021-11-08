/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:47:35 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:47:36 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_exit5(t_map_values *map)
{
	ft_printerror(4);
	ft_free_exit(map);
	exit(0);
}

void	ft_skip22222(int *i, int *j, char *str, t_map_values *map)
{
	*j = 0;
	while (str[*i] != ' ' && str[*i])
	{
		map->cfg.spr_tex[*j] = str[*i];
		*i += 1;
		*j += 1;
	}
}

void	ft_fill_sprite(t_map_values *map, char *str, int i, int j)
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
			if (!(map->cfg.spr_tex = (char *)malloc(sizeof(char) * (j + 1))))
				ft_exitm(map);
			i = tmp;
			ft_skip22222(&i, &j, str, map);
			map->cfg.spr_tex[j] = '\0';
			flag = 1;
		}
		else
			ft_exit5(map);
	}
	return ;
}

void	ft_fill_spritepath(t_map_values *map, char *str)
{
	int i;
	int j;

	i = 1;
	j = 0;
	ft_fill_sprite(map, str, i, j);
}

void	ft_spritepath(char *line, t_map_values *map)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == 'S')
		{
			ft_fill_spritepath(map, line + i);
			return ;
		}
		else
		{
			ft_printerror(4);
			ft_free_exit(map);
			exit(0);
		}
	}
	return ;
}
