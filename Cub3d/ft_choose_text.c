/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <Wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 00:44:08 by Wjena             #+#    #+#             */
/*   Updated: 2020/10/22 00:44:10 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_fill_text(t_map_values *map, char *str, int k)
{
	int i;
	int j;

	i = 2;
	j = 0;
	if (k == 1)
		ft_fill_notext(map, str, i, j);
	else if (k == 2)
		ft_fill_sotext(map, str, i, j);
	else if (k == 3)
		ft_fill_wetext(map, str, i, j);
	else if (k == 4)
		ft_fill_eatext(map, str, i, j);
	return ;
}

void	ft_path(char *line, t_map_values *map)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == 'N' && line[i + 1] == 'O')
			ft_fill_text(map, line + i, 1);
		else if (line[i] == 'S' && line[i + 1] == 'O')
			ft_fill_text(map, line + i, 2);
		else if (line[i] == 'W' && line[i + 1] == 'E')
			ft_fill_text(map, line + i, 3);
		else if (line[i] == 'E' && line[i + 1] == 'A')
			ft_fill_text(map, line + i, 4);
		else
		{
			ft_printerror(4);
			ft_free_exit(map);
			exit(0);
		}
		return ;
	}
	return ;
}
