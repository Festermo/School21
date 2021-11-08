/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:50:45 by festermo          #+#    #+#             */
/*   Updated: 2020/05/09 15:33:01 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

int				ft_isascii(int a);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
void			*ft_calloc(size_t num, size_t size);
int				ft_isalnum(int a);
int				ft_isalpha(int a);
int				ft_isdigit(int a);
int				ft_isprint(int a);
void			*ft_memccpy(void *dest, const void *source, int c, size_t n);
void			*ft_memchr(const void *arr, int c, size_t n);
int				ft_memcmp (const void *arr, const void *arr2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *source, size_t n);
void			*ft_memset(void *dst, int c, size_t n);
char			*ft_strchr(const char *str, int ch);
char			*ft_strdup(char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t k);
char			*ft_strrchr(const char *str, int ch);
int				ft_tolower(int a);
int				ft_toupper(int a);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_bzero(void *s, size_t n);

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
#endif
