/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:47:06 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:47:07 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_skip(char *str, int *i, int *j)
{
	while (str[*i] != ' ' && str[*i])
	{
		*i += 1;
		*j += 1;
	}
}

void	ft_skip2(int *i, int *j, char *str, t_map_values *map)
{
	*j = 0;
	while (str[*i] != ' ' && str[*i])
	{
		map->cfg.no_tex[*j] = str[*i];
		*i += 1;
		*j += 1;
	}
}

void	ft_skip22(int *i, int *j, char *str, t_map_values *map)
{
	*j = 0;
	while (str[*i] != ' ' && str[*i])
	{
		map->cfg.so_tex[*j] = str[*i];
		*i += 1;
		*j += 1;
	}
}

void	ft_skip222(int *i, int *j, char *str, t_map_values *map)
{
	*j = 0;
	while (str[*i] != ' ' && str[*i])
	{
		map->cfg.we_tex[*j] = str[*i];
		*i += 1;
		*j += 1;
	}
}

void	ft_skip2222(int *i, int *j, char *str, t_map_values *map)
{
	*j = 0;
	while (str[*i] != ' ' && str[*i])
	{
		map->cfg.ea_tex[*j] = str[*i];
		*i += 1;
		*j += 1;
	}
}
