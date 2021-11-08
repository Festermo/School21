/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:46:47 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:46:49 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putchar_fd(char c, int fd)
{
	if (!(write(fd, &c, 1)))
		return ;
}

void	ft_exit10(t_map_values *map)
{
	ft_free_exit(map);
	ft_printerror(4);
	exit(0);
}

void	ft_check_path(t_map_values *map)
{
	int	fd;

	if ((fd = open(map->cfg.no_tex, O_RDONLY)) < 0)
		ft_exit10(map);
	if ((fd = open(map->cfg.so_tex, O_RDONLY)) < 0)
		ft_exit10(map);
	if ((fd = open(map->cfg.ea_tex, O_RDONLY)) < 0)
		ft_exit10(map);
	if ((fd = open(map->cfg.we_tex, O_RDONLY)) < 0)
		ft_exit10(map);
	if ((fd = open(map->cfg.spr_tex, O_RDONLY)) < 0)
		ft_exit10(map);
	close(fd);
}
