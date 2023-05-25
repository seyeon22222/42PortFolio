/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:42:04 by seykim            #+#    #+#             */
/*   Updated: 2023/04/07 21:19:19 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *arr, ...)
{
	va_list	cur;
	int		res_len;
	t_flag	flag_str;

	flag_str = flag_init();
	va_start(cur, arr);
	res_len = 0;
	while (*arr)
	{
		if (*arr == '%')
		{
			arr++;
			res_len += printf_flag(arr, cur, flag_str);
			while (!find_conversion(arr))
				arr++;
		}
		else
			res_len += printf_char(*arr);
		if (*arr)
			arr++;
	}
	va_end(cur);
	return (res_len);
}

int	printf_format(const char *arr, va_list cur, t_flag flag_str)
{
	if (*arr == 'c')
		return (format_c(cur, flag_str));
	else if (*arr == 's')
		return (format_s(cur, flag_str));
	else if (*arr == 'p')
		return (format_p(cur, flag_str));
	// else if (*arr == 'd')
	// 	return (format_d(cur, flag_str));
	// else if (*arr == 'i')
	// 	return (format_i(arr, cur, flag_str));
	// else if (*arr == 'u')
	// 	return (format_u(arr, cur, flag_str));
	// else if (*arr == 'x')
	// 	return (format_x(arr, cur, flag_str));
	// else if (*arr == 'X')
	// 	return (format_X(arr, cur, flag_str));
	// else if (*arr == '%')
	// 	return (format_percent(arr, cur, flag_str));
	else
		return (-1);
}

int	format_d(va_list cur, t_flag flag_str)
{
	if (flag_str.shap == 0)
	{
		if (flag_str.minus == 1 && flag_str.zero == 0)
		{
			
		}
		else if (flag_str.zero == 1 && flag_str.minus == 0 && flag_str.precision == 0 && flag_str.dot == 0)
		{
			
		}
		else if (flag_str.space == 1)
		{
			write (1, " ", 1);
		}
		else if (flag_str.plus == 1)
		{
			
		}
	}
	return (-1);
}

int	format_c(va_list cur, t_flag flag_str)
{
	int		size;
	char	num;

	size = flag_str.width;
	num = va_arg(cur, int);
	if (flag_str.precision == 0 && flag_str.zero == 0 \
	&& flag_str.shap == 0 && flag_str.space == 0 && flag_str.plus == 0)
	{
		if (flag_str.minus == 1)
		{
			write (1, &num, 1);
			while (size-- > 1)
				write (1, " ", 1);
		}
		else if (flag_str.minus == 0)
		{
			while (size-- > 1)
				write (1, " ", 1);
			write (1, &num, 1);
		}
	}
	else
		return (-1);
	return (flag_str.width - size);
}

char	find_conversion(const char *arr)
{
	char	*conversion;

	conversion = "cspdiuxX%";
	while (*conversion)
	{
		if (*arr == *conversion)
			return (*conversion);
		conversion++;
	}
	return (0);
}

int	printf_char(const char arr)
{
	if (write(1, &arr, 1) == -1)
		return (-1);
	return (1);
}
