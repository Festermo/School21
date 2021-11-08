/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 15:31:42 by festermo          #+#    #+#             */
/*   Updated: 2020/05/09 15:32:19 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *a;
	t_list *b;

	if (lst && del && *lst)
	{
		a = *lst;
		while (a != NULL)
		{
			b = a->next;
			(*del)(a->content);
			free(a);
			a = b;
		}
		*lst = NULL;
	}
}
