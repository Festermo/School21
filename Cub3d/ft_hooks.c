/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:45:36 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:45:37 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_move_rigth(t_map_values *map, int *buf)
{
	map->dir -= M_PI_2;
	while (*buf < 10)
	{
		map->x_pl -= (sin(map->dir) / 10 / 4);
		map->y_pl -= (cos(map->dir) / 10 / 4);
		if (map->cfg.map[(int)(map->x_pl)][(int)(map->y_pl)] == '1')
		{
			map->x_pl += (sin(map->dir) / 10 * (*buf + 1) / 4);
			map->y_pl += (cos(map->dir) / 10 * (*buf + 1) / 4);
			break ;
		}
		*buf = *buf + 1;
	}
	map->dir += M_PI_2;
}

void	ft_move_left(t_map_values *map, int *buf)
{
	map->dir += M_PI_2;
	while (*buf < 10)
	{
		map->x_pl -= (sin(map->dir) / 10 / 4);
		map->y_pl -= (cos(map->dir) / 10 / 4);
		if (map->cfg.map[(int)(map->x_pl)][(int)(map->y_pl)] == '1')
		{
			map->x_pl += (sin(map->dir) / 10 * (*buf + 1) / 4);
			map->y_pl += (cos(map->dir) / 10 * (*buf + 1) / 4);
			break ;
		}
		*buf = *buf + 1;
	}
	map->dir -= M_PI_2;
}

void	ft_move_backward(t_map_values *map, int *buf)
{
	while (*buf < 10)
	{
		map->x_pl -= (sin(map->dir) / 10 / 2);
		map->y_pl -= (cos(map->dir) / 10 / 2);
		if (map->cfg.map[(int)(map->x_pl)][(int)(map->y_pl)] == '1')
		{
			map->x_pl += (sin(map->dir) / 10 * (*buf + 1) / 2);
			map->y_pl += (cos(map->dir) / 10 * (*buf + 1) / 2);
			break ;
		}
		*buf = *buf + 1;
	}
}

void	ft_move_forward(t_map_values *map, int *buf)
{
	while (*buf < 10)
	{
		map->x_pl += (sin(map->dir) / 10 / 2);
		map->y_pl += (cos(map->dir) / 10 / 2);
		if (map->cfg.map[(int)(map->x_pl)][(int)(map->y_pl)] == '1')
		{
			map->x_pl -= (sin(map->dir) / 10 * (*buf + 1) / 2);
			map->y_pl -= (cos(map->dir) / 10 * (*buf + 1) / 2);
			break ;
		}
		*buf = *buf + 1;
	}
}

int		ft_keys(int key, t_map_values *map)
{
	int buf;

	buf = 0;
	ft_destroy_and_clear(map);
	if (key == 13)
		ft_move_forward(map, &buf);
	else if (key == 1)
		ft_move_backward(map, &buf);
	else if (key == 123)
		map->dir -= 0.1;
	else if (key == 124)
		map->dir += 0.1;
	else if (key == 0)
		ft_move_left(map, &buf);
	else if (key == 2)
		ft_move_rigth(map, &buf);
	else if (key == 53)
		ft_close_esc(map);
	while (map->dir > 2 * M_PI)
		map->dir -= 2 * M_PI;
	while (map->dir < -2 * M_PI)
		map->dir += 2 * M_PI;
	ft_make_map(map->cfg.map, map);
	return (0);
}
