/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_xx1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:38:17 by seykim            #+#    #+#             */
/*   Updated: 2023/04/04 15:57:06 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_x(va_list cur)
{
	int	size;

	size = 0;
	size += format_hex_x(cur, 0, "0123456789abcdef");
	return (size);
}

int	format_x1(va_list cur)
{
	int	size;

	size = 0;
	size += format_hex_x(cur, 0, "0123456789ABCDEF");
	return (size);
}

int	format_percent(const char *arr)
{
	return (printf_char(*arr++));
}
