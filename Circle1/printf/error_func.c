/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:02:27 by seykim            #+#    #+#             */
/*   Updated: 2023/04/06 17:22:42 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cnt_percent(const char *str)
{
	str++;
	return (1);
}

int	cnt_hex_x(va_list cur2, int idx, char *base)
{
	unsigned int	num;
	char			num_str[17];

	num = (unsigned int)va_arg(cur2, void *);
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
	idx = 0;
	while (num_str[idx])
		idx++;
	return (idx);
}

int	cnt_dec(va_list cur2, int idx)
{
	int		num;
	char	num_str[11];
	int		flag;

	num = va_arg(cur2, int);
	flag = 0;
	if (num == -2147483648)
		return (11);
	if (num < 0)
	{
		num = -num;
		flag = 1;
	}
	str_add(num_str, &idx, num);
	idx = 0;
	while (num_str[idx])
		idx++;
	return (idx + flag);
}

int	cnt_hex(va_list cur2, int idx, char *base)
{
	unsigned long	num;
	char			num_str[17];

	num = (unsigned long)va_arg(cur2, void *);
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
	idx = 0;
	while (num_str[idx])
		idx++;
	return (idx);
}
