/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:46:12 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:46:13 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		get_pixel_color(t_map_values *map, int x, int y)
{
	char	*dst;
	int		index;

	index = y * map->actsize_line + x * (map->actbpp / 8);
	dst = map->actadr + index;
	return (*(unsigned int*)dst);
}

void	my_pixel_put(t_map_values *map, int x, int y, int color)
{
	char *dst;

	dst = map->imgadr.addr1 + ((y * map->imgadr.size_line1) +
	(x * (map->imgadr.bpp1 / 8)));
	*(unsigned int*)dst = color;
}

int		ft_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
