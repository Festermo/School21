/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:19:30 by festermo          #+#    #+#             */
/*   Updated: 2020/07/07 16:07:37 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>

char		*ft_itoa_hex(unsigned int value);
char		*ft_itoa_hex_upper(unsigned int value);
char		*ft_itoa_hex_ptr(unsigned long value);
void		ft_print_hex_low(unsigned int numb, char *flags,
			int *star, int *ret_val);
void		ft_print_hex_up(unsigned int numb, char *flags,
			int *star, int *ret_val);
void		ft_print_ptr(long long n, char *flags, int *ret_val, int *star);
void		ft_print_unsigned(unsigned int numb, char *flags,
			int *star, int *ret_val);
void		ft_printchar(char symb, char *flags, int *ret_val, int *star);
int			ft_printf(const char *s, ...);
int			ft_number_of_params(const char *s);
const char	*ft_print_before_param(const char *s, int *ret_val);
const char	*ft_get_flags(const char *s, char **flags, char *param);
void		ft_printnbr(int numb, char *flags, int *star, int *ret_val);
void		ft_print_str(char *str, char *flags, int *star, int *ret_val);
void		ft_putnbr_fd_long(long n, int fd);
void		ft_putnbr_fd_unsigned(unsigned int n, int fd);
void		ft_which_par(char param, char *flags, va_list ap, int *ret_val);
const char	*ft_par_handling(const char *s, int numb_of_par,
			va_list ap, int *ret_val);
char		*ft_length_init(char *flags, int *star, int *length, char *symb);
void		ft_hex_init_width(int *width, int *star, char *flags);
void		ft_hex_low_wll1(int *width, int *ret_val, int *length, int numb);
int			ft_hex_low_wll2(int *width, int *length, int numb, char *symb);
int			ft_hex_low_wsl(char *flags, int *length, int numb, char *symb);
int			ft_hex_low_nd(char *flags, int *length, int numb, char *symb);
void		ft_hex_znazw(int *length, int *ret_val, int which_case, int numb);
int			ft_hex_up_nd(char *flags, int *length, int numb, char *symb);
int			ft_hex_up_wsl(char *flags, int *length, int numb, char *symb);
int			ft_hex_up_wll2(int *width, int *length, int numb, char *symb);
void		ft_hex_up_wll1(int *width, int *ret_val, int *length, int numb);
void		ft_options_ptr(char *flags, int *ret_val, int *length, char *b);
void		ft_uns_init_width(int *width, int *star, char *flags);
int			ft_wbl1_uns(int *length, int *width, int numb);
int			ft_wbl2_uns(int *length, int *width, int numb, char *symb);
int			ft_wsl_uns(char *flags, int *length, int numb, char *symb);
int			ft_count_digits(unsigned int n);
int			ft_wz_unsg(char *flags, char *symb, int *length, int numb);
void		ft_nbr_init_width(int *width, int *star, char *flags);
int			ft_wbl1_nbr(int numb, int *length, int *width);
int			ft_wbl2_nbr(int numb, int *length, int *width);
int			ft_wbl3_nbr(int numb, char *symb, int *length, int *width);
int			ft_wbl4_nbr(int numb, int *width, int *length, char *symb);
int			ft_wsl1_nbr(int numb, int *length, char *flags, int *width);
int			ft_wsl2_nbr(int *numb, int *width, int *length);
int			ft_wsl3_nbr(int *width, int numb);
int			ft_wsl4_nbr(int numb, int *length, char *flags);
int			ft_wz1_nbr(int numb, int *length, char *symb);
int			ft_wz2_nbr(int *numb, int *length, char *symb);
int			ft_wz3_nbr(int *numb, int *length, char *symb);
void		ft_minint (int *width, int *length, int which_case, int *ret_val);
int			ft_nbr_wzall(char *flags, int numb, int length, char symb);
int			ft_nbr_wslall(int numb, int width, int length, char *flags);
int			ft_nbr_wblall(int numb, int width, int length, char *flags);
int			ft_str_length_init(int *star, char **flags,
			int *length, char **str);
void		ft_str_width_init(int *star, char *flags, char *str, int *width);
int			ft_str_wnz(int *width, char *str, int *length);
int			ft_str_wnz2(int *length);
int			ft_wz1_str(char *str, int *width, int *length);
int			ft_wz2_str(char *str, int buf);
int			ft_nw_str(int *length, char *str, char *flags);
int			ft_str_wzall(int width, char *str, int length);
int			*get_star(char *flags, va_list ap, int *star);
const char	*ft_get_flags2(const char *s, char **flags, int *i);
void		ft_wz31_nbr(int *numb, int *length, char *symb, int *i);
void		ft_wz21_nbr(int *numb, int *length, char *symb, int *i);
char		*ft_null_str_opt(int *flag, char **str);
void		ft_length_short(int numb, int *width, int *length, int *ret_val);

#endif
