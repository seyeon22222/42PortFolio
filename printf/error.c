/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:29:08 by seykim            #+#    #+#             */
/*   Updated: 2023/04/06 18:54:38 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_error(const char *arr, va_list cur2)
{
	long long		cnt;
	const char		*str;

	cnt = 0;
	str = arr;
	while (*str)
	{
		if (*str == '%')
			cnt += (long long)cnt_format(++str, cur2);
		else
			cnt += 1;
		str++;
	}
	if (cnt >= 2147483647)
		return (-1);
	return (1);
}

int	cnt_format(const char *str, va_list cur2)
{
	if (*str == 'c')
		return (cnt_c(cur2));
	else if (*str == 's')
		return (cnt_s(cur2));
	else if (*str == 'p')
		return (cnt_p(cur2));
	else if (*str == 'd')
		return (cnt_d(cur2));
	else if (*str == 'i')
		return (cnt_d(cur2));
	else if (*str == 'u')
		return (cnt_u(cur2));
	else if (*str == 'x')
		return (cnt_x(cur2));
	else if (*str == 'X')
		return (cnt_x(cur2));
	else if (*str == '%')
		return (cnt_percent(str));
	else
		return (0);
}

int	cnt_ui(unsigned int nb)
{
	unsigned int	num;
	unsigned int	size;
	int				temp;

	num = 0;
	size = 1;
	if (nb / 10 != 0)
	{
		temp = cnt_ui(nb / 10);
		size += temp;
	}
	num = nb % 10;
	return (size);
}

int	cnt_x(va_list cur2)
{
	int	size;

	size = 0;
	size += cnt_hex_x(cur2, 0, "0123456789abcdef");
	return (size);
}
