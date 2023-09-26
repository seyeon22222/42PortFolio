/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:18:54 by seykim            #+#    #+#             */
/*   Updated: 2023/03/31 14:44:10 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_s_no_dot(t_flag flag_str, char *str, int size)
{
	int	str_len;
	int	cnt;

	str_len = ft_strlen(str);
	size = flag_str.width;
	cnt = size - str_len;
	if (flag_str.width == 0)
	{
		size = ft_strlen(str);
		while (size--)
			write(1, str++, 1);
		return (str_len);
	}
	if (flag_str.width <= str_len)
	{
		size = str_len;
		while (size--)
			write(1, str++, 1);
		return (str_len);
	}
	return (format_no_dot_abs(flag_str, str, size));
}

int	format_no_dot_abs(t_flag flag_str, char *str, int size)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (flag_str.minus == 0)
	{	
		size = flag_str.width;
		while (flag_str.width-- - str_len)
			write(1, " ", 1);
		while (str_len--)
			write(1, str++, 1);
		return (size);
	}
	else
	{
		size = flag_str.width;
		while (str_len--)
			write(1, str++, 1);
		while (flag_str.width-- - str_len)
			write(1, " ", 1);
		return (size);
	}
	return (0);
}
