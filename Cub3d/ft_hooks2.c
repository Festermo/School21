/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:45:45 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:45:47 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_mouse(t_map_values *map)
{
	ft_free_exit(map);
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
	return (0);
}

void	ft_destroy_and_clear(t_map_values *map)
{
	mlx_destroy_image(map->mlx, map->imgadr.img1);
	mlx_destroy_image(map->mlx, map->imgadr.img);
	mlx_destroy_image(map->mlx, map->imgadr.img2);
	mlx_destroy_image(map->mlx, map->imgadr.img3);
	mlx_destroy_image(map->mlx, map->imgadr.img4);
	mlx_destroy_image(map->mlx, map->imgadr.img5);
	mlx_clear_window(map->mlx, map->win);
}

void	ft_close_esc(t_map_values *map)
{
	ft_free_exit(map);
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
}
