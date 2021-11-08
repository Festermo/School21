/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:43:57 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:43:59 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_check_full1(t_map_values *map)
{
	if (map->cfg.w_wid <= 0)
		ft_exit7(map);
	if (map->cfg.w_he <= 0)
		ft_exit7(map);
	if (map->cfg.no_tex == NULL)
		ft_exit7(map);
	if (map->cfg.so_tex == NULL)
		ft_exit7(map);
	if (map->cfg.we_tex == NULL)
		ft_exit7(map);
	if (map->cfg.ea_tex == NULL)
		ft_exit7(map);
	if (map->cfg.spr_tex == NULL)
		ft_exit7(map);
	if (map->cfg.floor_red < 0 || map->cfg.floor_red > 255)
		ft_exit7(map);
	if (map->cfg.floor_green < 0 || map->cfg.floor_green > 255)
		ft_exit7(map);
	if (map->cfg.flag1 == 0 || map->cfg.flag == 0)
		ft_exit7(map);
	if (map->cfg.flagrf == 0 || map->cfg.flaggf == 0 || map->cfg.flagbf == 0
		|| map->cfg.flagrc == 0 || map->cfg.flaggc == 0 || map->cfg.flagbc == 0)
		ft_exit7(map);
}

void	ft_check_full(t_map_values *map)
{
	ft_check_full1(map);
	if (map->cfg.floor_blue < 0 || map->cfg.floor_blue > 255)
		ft_exit7(map);
	if (map->cfg.cell_red < 0 || map->cfg.cell_red > 255)
		ft_exit7(map);
	if (map->cfg.cell_green < 0 || map->cfg.cell_green > 255)
		ft_exit7(map);
	if (map->cfg.cell_blue < 0 || map->cfg.cell_blue > 255)
		ft_exit7(map);
	if (map->cfg.map == NULL)
		ft_exit7(map);
	if (map->cfg.w_wid > 1920)
	{
		map->cfg.w_wid = 1920;
	}
	if (map->cfg.w_he > 1080)
		map->cfg.w_he = 1080;
	if (map->cfg.w_he < 8 && map->cfg.w_wid < 8)
	{
		map->cfg.w_he = 8;
		map->cfg.w_wid = 8;
	}
}

void	ft_map_init(t_map_values *map)
{
	map->cfg.w_wid = 0;
	map->cfg.w_he = 0;
	map->cfg.no_tex = NULL;
	map->cfg.so_tex = NULL;
	map->cfg.we_tex = NULL;
	map->cfg.ea_tex = NULL;
	map->cfg.spr_tex = NULL;
	map->cfg.floor_red = 0;
	map->cfg.floor_green = 0;
	map->cfg.floor_blue = 0;
	map->cfg.cell_red = 0;
	map->cfg.cell_green = 0;
	map->cfg.cell_blue = 0;
	map->cfg.map = NULL;
	map->cfg.size = 0;
	map->cfg.flag = 0;
	map->cfg.flag1 = 0;
	map->cfg.flagrf = 0;
	map->cfg.flaggf = 0;
	map->cfg.flagbf = 0;
	map->cfg.flagrc = 0;
	map->cfg.flaggc = 0;
	map->cfg.flagbc = 0;
}

void	ft_read_file(int fd, char **line, int *flag, t_map_values *map)
{
	while (get_next_line(fd, line))
	{
		ft_razdel(line, flag, map);
		free(*line);
	}
}

void	ft_lets_parse(t_map_values *map, char *argv)
{
	int		fd;
	int		ld;
	char	*line;
	char	*line1;
	int		flag;

	ld = open(argv, O_RDONLY);
	fd = open(argv, O_RDONLY);
	line = NULL;
	line1 = NULL;
	flag = 0;
	ft_init_map(map, ld, &line1);
	ft_read_file(fd, &line, &flag, map);
	ft_map(line, map, &flag);
	free(line);
	ft_check_full(map);
	ft_map_check(map);
	ft_check_path(map);
	close(fd);
	close(ld);
}
