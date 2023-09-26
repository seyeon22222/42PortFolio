/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:49:47 by seykim            #+#    #+#             */
/*   Updated: 2023/03/31 14:42:35 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_strbig_plus(t_flag flag_str, char *str, int size)
{
	if (flag_str.width < flag_str.precision)
	{
		size = flag_str.precision;
		while (size--)
			write(1, str++, 1);
		return (flag_str.precision);
	}
	else if (flag_str.width >= flag_str.precision)
	{
		size = flag_str.width;
		while (flag_str.width-- - flag_str.precision > 0)
			write(1, " ", 1);
		while (flag_str.precision--)
			write(1, str++, 1);
		return (size);
	}
	return (0);
}

int	format_strbig_plus2(t_flag flag_str, char *str, int size)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (flag_str.width < flag_str.precision)
	{
		size = ft_strlen(str);
		while (flag_str.width-- - ft_strlen(str) > 0)
		{
			write(1, " ", 1);
			size++;
		}
		while (str_len--)
			write(1, str++, 1);
		return (size);
	}
	else if (flag_str.width >= flag_str.precision)
	{
		size = flag_str.width;
		while (flag_str.width-- - ft_strlen(str) > 0)
			write(1, " ", 1);
		while (str_len--)
			write(1, str++, 1);
		return (size);
	}
	return (0);
}
