/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:10:13 by seykim            #+#    #+#             */
/*   Updated: 2023/04/03 21:36:27 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_d(va_list cur)
{
	int	size;
	int	temp;

	size = 0;
	temp = format_dec(cur, 0);
	if (temp < 0)
		return (-1);
	size += temp;
	return (size);
}

int	format_i(va_list cur)
{
	int	size;
	int	temp;

	size = 0;
	temp = format_dec(cur, 0);
	if (temp < 0)
		return (-1);
	size += temp;
	return (size);
}

int	format_u(va_list cur)
{
	unsigned int	num;
	int				size;

	num = va_arg(cur, unsigned int);
	size = 0;
	size += ft_putnbr_ui(num);
	return (size);
}
