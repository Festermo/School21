/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:42:50 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:42:55 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void			write_bmp_image(t_map_values *map, int fd)
{
	int i;
	int row;
	int firstinrow;
	int lastinrow;

	i = map->cfg.w_he * map->cfg.w_wid - 1;
	while (i >= 0)
	{
		row = ((int)(i / map->cfg.w_wid)) + 1;
		firstinrow = map->cfg.w_wid * row - map->cfg.w_wid;
		lastinrow = ((row - 1) * map->cfg.w_wid) + map->cfg.w_wid - 1;
		while (firstinrow <= lastinrow)
		{
			write(fd, &(map->imgadr.addr1[firstinrow *
			map->imgadr.bpp1 / 8]), 4);
			i--;
			firstinrow++;
		}
	}
}

void			write_bmp_info(t_map_values *map, int fd)
{
	int info_header;
	int color_plane;
	int zeroes;
	int res;

	info_header = 40;
	color_plane = 1;
	zeroes = 0;
	res = 2835;
	write(fd, &info_header, 4);
	write(fd, &(map->cfg.w_wid), 4);
	write(fd, &(map->cfg.w_he), 4);
	write(fd, &color_plane, 2);
	write(fd, &map->imgadr.bpp1, 2);
	while (zeroes++ < 8)
		write(fd, "\0", 1);
	write(fd, &res, 4);
	write(fd, &res, 4);
	zeroes = 0;
	while (zeroes++ < 12)
		write(fd, "\0", 1);
}

void			ft_bmp(t_map_values *map)
{
	int offset;
	int img_size;

	offset = 58;
	img_size = offset + (map->cfg.w_wid * map->cfg.w_he * 4);
	write(map->bmp.fd, "BM", 2);
	write(map->bmp.fd, &img_size, 4);
	write(map->bmp.fd, "\0\0\0\0", 4);
	write(map->bmp.fd, &offset, 4);
	write_bmp_info(map, map->bmp.fd);
	write_bmp_image(map, map->bmp.fd);
	close(map->bmp.fd);
	ft_free_exit(map);
	exit(0);
}

void			ft_whatsize(char *line, t_map_values *map)
{
	int i;

	i = 0;
	while (line[i] != '\0')
		i++;
	if (i > map->cfg.size)
		map->cfg.size = i;
}
