/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:40:29 by seykim            #+#    #+#             */
/*   Updated: 2023/04/06 18:55:24 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *arr, ...);
int		printf_format(const char *arr, va_list cur);
int		printf_char(const char arr);
int		format_c(va_list cur);
int		format_s(va_list cur);
int		format_p(va_list cur);
int		format_d(va_list cur);
int		format_i(va_list cur);
int		format_u(va_list cur);
int		format_x(va_list cur);
int		format_x1(va_list cur);
int		format_percent(const char *arr);
int		format_hex(va_list cur, int idx, char *base);
int		format_hex_x(va_list cur, int idx, char *base);
int		format_dec(va_list cur, int idx);
void	ft_strrev(char *num_str);
int		excp(void);
void	str_add(char *num_str, int *idx, int num);
int		ft_strlen(const char *s);
int		ft_putnbr_ui(unsigned int nb);
int		len_error(const char *str, va_list cur);
int		cnt_format(const char *str, va_list cur2);
int		cnt_ui(unsigned int nb);
int		cnt_x(va_list cur2);
int		cnt_c(va_list cur2);
int		cnt_s(va_list cur2);
int		cnt_p(va_list cur2);
int		cnt_d(va_list cur2);
int		cnt_u(va_list cur2);
int		cnt_percent(const char *str);
int		cnt_hex_x(va_list cur2, int idx, char *base);
int		cnt_dec(va_list cur2, int idx);
int		cnt_hex(va_list cur2, int idx, char *base);

#endif
