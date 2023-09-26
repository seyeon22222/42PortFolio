/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:47:40 by seykim            #+#    #+#             */
/*   Updated: 2023/04/04 15:57:40 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_hex(va_list cur, int idx, char *base)
{
	unsigned long	num;
	char			num_str[17];

	num = (unsigned long)va_arg(cur, void *);
	if (num == 0)
		num_str[idx++] = base[num % 16];
	while (num != 0)
	{
		num_str[idx] = base[num % 16];
		num /= 16;
		idx++;
	}
	num_str[idx] = 0;
	ft_strrev(num_str);
	idx = -1;
	while (num_str[++idx])
	{
		if (printf_char(num_str[idx]) < 0)
			return (-1);
	}
	return (idx);
}

void	ft_strrev(char *num_str)
{
	int		idx;
	int		size;
	char	temp;

	idx = 0;
	size = ft_strlen(num_str);
	while (idx < (size / 2))
	{
		temp = num_str[idx];
		num_str[idx] = num_str[size - idx - 1];
		num_str[size - idx - 1] = temp;
		idx++;
	}
}

int	format_hex_x(va_list cur, int idx, char *base)
{
	unsigned int	num;
	char			num_str[17];

	num = (unsigned int)va_arg(cur, void *);
	if (num == 0)
		num_str[idx++] = base[num % 16];
	while (num != 0)
	{
		num_str[idx] = base[num % 16];
		num /= 16;
		idx++;
	}
	num_str[idx] = 0;
	ft_strrev(num_str);
	idx = -1;
	while (num_str[++idx])
	{
		if (printf_char(num_str[idx]) < 0)
			return (-1);
	}
	return (idx);
}
