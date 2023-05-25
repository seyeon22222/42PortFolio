/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:03:11 by seykim            #+#    #+#             */
/*   Updated: 2023/04/06 18:37:37 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cnt_c(va_list cur2)
{
	char	num;

	num = va_arg(cur2, int);
	return (1);
}

int	cnt_s(va_list cur2)
{
	int		size;
	char	*num;

	num = va_arg(cur2, char *);
	size = 0;
	if (!num)
		return (6);
	while (*num)
	{
		size++;
		num++;
	}
	return (size);
}

int	cnt_p(va_list cur2)
{
	int		size;

	size = 0;
	size += cnt_hex(cur2, 0, "0123456789abcdef");
	return (size + 2);
}

int	cnt_d(va_list cur2)
{
	int	size;

	size = 0;
	size += cnt_dec(cur2, 0);
	return (size);
}

int	cnt_u(va_list cur2)
{
	unsigned int	num;
	int				size;

	num = va_arg(cur2, unsigned int);
	size = 0;
	size += cnt_ui(num);
	return (size);
}
