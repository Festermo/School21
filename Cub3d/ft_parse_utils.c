/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:46:38 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:46:40 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_printerror(int numer)
{
	ft_putstr_fd("Error\n", 1);
	if (numer == 1)
		ft_putstr_fd("Invalid floor color\n", 1);
	if (numer == 2)
		ft_putstr_fd("Invalid ceiling color\n", 1);
	if (numer == 3)
		ft_putstr_fd("Invalid resolution\n", 1);
	if (numer == 4)
		ft_putstr_fd("Invalid textures path\n", 1);
	if (numer == 5)
		ft_putstr_fd("Invalid map\n", 1);
	if (numer == 6)
		ft_putstr_fd("Invalid start game\n", 1);
	if (numer == 7)
		ft_putstr_fd("Invalid malloc\n", 1);
}

void	ft_free_map(t_map_values *map)
{
	int i;

	i = 0;
	if (map->cfg.map != NULL)
	{
		while (map->cfg.map[i] != NULL)
		{
			free(map->cfg.map[i]);
			i++;
		}
		free(map->cfg.map);
	}
}

void	ft_free_exit(t_map_values *map)
{
	if (map->cfg.no_tex != NULL)
		free(map->cfg.no_tex);
	if (map->cfg.we_tex != NULL)
		free(map->cfg.we_tex);
	if (map->cfg.ea_tex != NULL)
		free(map->cfg.ea_tex);
	if (map->cfg.so_tex != NULL)
		free(map->cfg.so_tex);
	if (map->cfg.spr_tex != NULL)
		free(map->cfg.spr_tex);
	ft_free_map(map);
	ft_free_sprites(map);
}

int		ft_argv(char *str)
{
	if (str[0] != 'm')
		return (0);
	if (str[1] != 'a')
		return (0);
	if (str[2] != 'p')
		return (0);
	if (str[3] != '.')
		return (0);
	if (str[4] != 'c')
		return (0);
	if (str[5] != 'u')
		return (0);
	if (str[6] != 'b')
		return (0);
	if (str[7] != '\0')
		return (0);
	return (1);
}

int		ft_argv1(char *str)
{
	if (str[0] != '-')
		return (0);
	if (str[1] != '-')
		return (0);
	if (str[2] != 's')
		return (0);
	if (str[3] != 'a')
		return (0);
	if (str[4] != 'v')
		return (0);
	if (str[5] != 'e')
		return (0);
	if (str[6] != '\0')
		return (0);
	return (1);
}
