/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:40:29 by seykim            #+#    #+#             */
/*   Updated: 2023/04/03 20:21:43 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_flag
{
	int	shap;
	int	space;
	int	zero;
	int	minus;
	int	plus;
	int	width;
	int	precision;
	int	dot;
}	t_flag;

int		ft_printf(const char *arr, ...);
int		printf_format(const char *arr, va_list cur, t_flag flag_str);
int		format_c(va_list cur, t_flag flag_str);
char	find_conversion(const char *arr);
int		printf_char(const char arr);
t_flag	flag_init(void);
int		ft_atoi(const char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
int		ft_strlen(const char *s);
int		printf_flag(const char *arr, va_list cur, t_flag flag_str);
int		printf_width(const char *arr, va_list cur, t_flag flag_str);
int		printf_precision(const char *arr, va_list cur, t_flag flag_str);
int		format_s(va_list cur, t_flag flag_str);
int		format_s_nominus(t_flag flag_str, char *str, int size);
int		format_s_minus(t_flag flag_str, char *str, int size);
int		format_s_no_dot(t_flag flag_str, char *str, int size);
int		format_no_dot_abs(t_flag flag_str, char *str, int size);
int		format_strbig_plus(t_flag flag_str, char *str, int size);
int		format_strbig_plus2(t_flag flag_str, char *str, int size);
int		format_strbig_minus2(t_flag flag_str, char *str, int size);
int		format_strbig_minus(t_flag flag_str, char *str, int size);
int		format_p(va_list cur, t_flag flag_str);
int		format_p_minus(va_list cur, t_flag flag_str);
int		format_p_nominus(va_list cur, t_flag flag_str);
int		format_p_w(va_list cur, int idx);
void	ft_strrev(char *num_str);
void	*ft_memset(void *b, int c, size_t len);

#endif
