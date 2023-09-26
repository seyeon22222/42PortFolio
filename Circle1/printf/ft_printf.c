/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:17:32 by seykim            #+#    #+#             */
/*   Updated: 2023/04/06 18:54:32 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *arr, ...)
{
	va_list		cur;
	va_list		cur2;
	int			res_len;
	int			temp;

	va_start(cur, arr);
	va_copy(cur2, cur);
	res_len = 0;
	if (len_error(arr, cur2) < 0)
		return (-1);
	while (*arr)
	{
		if (*arr == '%')
			temp = printf_format(++arr, cur);
		else
			temp = printf_char(*arr);
		if (temp < 0)
			return (temp);
		res_len += temp;
		arr++;
	}
	va_end(cur);
	va_end(cur2);
	return (res_len);
}

int	printf_format(const char *arr, va_list cur)
{
	if (*arr == 'c')
		return (format_c(cur));
	else if (*arr == 's')
		return (format_s(cur));
	else if (*arr == 'p')
		return (format_p(cur));
	else if (*arr == 'd')
		return (format_d(cur));
	else if (*arr == 'i')
		return (format_i(cur));
	else if (*arr == 'u')
		return (format_u(cur));
	else if (*arr == 'x')
		return (format_x(cur));
	else if (*arr == 'X')
		return (format_x1(cur));
	else if (*arr == '%')
		return (format_percent(arr));
	else
		return (printf_char(*arr));
}

int	printf_char(const char arr)
{
	if (write(1, &arr, 1) < 0)
		return (-1);
	return (1);
}
