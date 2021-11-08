/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:43:33 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:43:35 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_check_screen(int argc, char **argv, t_map_values *map)
{
	if (argc == 3 && ft_argv1(argv[2]) == 1)
	{
		map->bmp.fd = open("screen.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		map->bmp.flag = 2;
	}
	else if (argc == 3 && ft_argv1(argv[2]) == 0)
	{
		ft_free_exit(map);
		ft_printerror(6);
		exit(0);
	}
}

void	ft_check_argc(int argc, t_map_values *map, char **argv)
{
	if (argc == 1)
	{
		ft_printerror(6);
		exit(0);
	}
	if (argc > 3)
	{
		ft_printerror(6);
		exit(0);
	}
	if (ft_argv(argv[1]) == 1)
		ft_lets_parse(map, argv[1]);
	else if (ft_argv(argv[1]) == 0)
	{
		ft_printerror(6);
		exit(0);
	}
}

void	ft_razdel(char **line, int *flag, t_map_values *map)
{
	if (*line[0] == '\0' && *flag == 0)
		return ;
	else if (map->cfg.w_he == 0 && map->cfg.w_wid == 0 && f(*line) == 'R')
		ft_window(*line, map);
	else if (map->cfg.no_tex == NULL && f(*line) == 'N')
		ft_path(*line, map);
	else if (map->cfg.so_tex == NULL && f(*line) == 'S' && t(*line) == 'O')
		ft_path(*line, map);
	else if (map->cfg.we_tex == NULL && f(*line) == 'W')
		ft_path(*line, map);
	else if (map->cfg.ea_tex == NULL && f(*line) == 'E')
		ft_path(*line, map);
	else if (map->cfg.spr_tex == NULL && f(*line) == 'S')
		ft_spritepath(*line, map);
	else if (map->cfg.floor_red == 0 && map->cfg.floor_green == 0
		&& map->cfg.floor_blue == 0 && f(*line) == 'F')
		ft_floor(*line, map);
	else if (map->cfg.cell_red == 0 && map->cfg.cell_green == 0
		&& map->cfg.cell_blue == 0 && f(*line) == 'C')
		ft_cell(*line, map);
	else
		ft_map(*line, map, flag);
	return ;
}
