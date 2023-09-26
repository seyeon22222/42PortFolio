/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:48:20 by seykim            #+#    #+#             */
/*   Updated: 2023/04/04 15:54:02 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_c(va_list cur)
{
	char	num;

	num = va_arg(cur, int);
	return (printf_char(num));
}

int	format_s(va_list cur)
{
	int		size;
	char	*num;

	num = va_arg(cur, char *);
	size = 0;
	if (!num)
	{
		if (write (1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	while (*num)
	{
		if (printf_char(*num) == -1)
			return (-1);
		size++;
		num++;
	}
	return (size);
}

int	format_p(va_list cur)
{
	char	*p;
	int		size;

	p = "0x";
	size = 0;
	while (*p)
	{
		if (printf_char(*p) < 0)
			return (-1);
		p++;
	}
	size += format_hex(cur, 0, "0123456789abcdef");
	return (size + 2);
}
