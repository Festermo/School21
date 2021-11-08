/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 14:33:24 by festermo          #+#    #+#             */
/*   Updated: 2020/05/09 14:33:37 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *a;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		a = *lst;
		while (a->next)
			a = a->next;
		a->next = new;
	}
}
