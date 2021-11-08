/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:17:37 by festermo          #+#    #+#             */
/*   Updated: 2020/06/20 16:19:01 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

int		if_negative(int n);
int		count_tens(int n, int sign);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strrchr(const char *str, int ch);
void	*ft_memset(void *dest, int val, size_t len);

#endif
