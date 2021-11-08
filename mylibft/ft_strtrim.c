/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:28:10 by festermo          #+#    #+#             */
/*   Updated: 2020/05/08 20:44:22 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_k(char const *s1, char const *set, int j)
{
	int k;

	k = ft_strlen(s1) - 1;
	while (set[j] && s1[k])
	{
		if (s1[k] == set[j])
		{
			k--;
			j = -1;
		}
		j++;
	}
	return (k);
}

static int		ft_get_i(char const *s1, char const *set, int j)
{
	int i;

	i = 0;
	while (set[j] && s1[i])
	{
		if (s1[i] == set[j])
		{
			j = -1;
			i++;
		}
		j++;
	}
	return (i);
}

static void		ft_fill_ans(char const *s1, char const *set, int j, char *ans)
{
	int f;
	int i;

	f = 0;
	i = j;
	while (f < (ft_get_k(s1, set, 0) - j + 1))
	{
		ans[f] = s1[i];
		f++;
		i++;
	}
	ans[f] = '\0';
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = ft_get_i(s1, set, 0);
	if ((ft_get_k(s1, set, 0) - i) < 0)
	{
		if (!(ans = (char*)malloc(sizeof(char))))
			return (NULL);
		ans[0] = '\0';
		return (ans);
	}
	if (!(ans = (char*)malloc(sizeof(char) * (ft_get_k(s1, set, 0) - i + 2))))
		return (NULL);
	j = i;
	ft_fill_ans(s1, set, j, ans);
	return (ans);
}
