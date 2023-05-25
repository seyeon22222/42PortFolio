/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_minus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:50:38 by seykim            #+#    #+#             */
/*   Updated: 2023/03/31 14:10:39 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_strbig_minus(t_flag flag_str, char *str, int size)
{
	int	cnt;

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
		cnt = flag_str.precision;
		while (flag_str.precision--)
			write(1, str++, 1);
		while (flag_str.width-- - cnt > 0)
			write(1, " ", 1);
		return (size);
	}
	return (0);
}

int	format_strbig_minus2(t_flag flag_str, char *str, int size)
{
	int	str_len;
	int	cnt;

	str_len = ft_strlen(str);
	cnt = str_len;
	if (flag_str.width < flag_str.precision)
	{
		size = ft_strlen(str);
		while (str_len--)
			write(1, str++, 1);
		while (flag_str.width-- - cnt > 0 && size++)
			write(1, " ", 1);
		return (size);
	}
	else if (flag_str.width >= flag_str.precision)
	{
		size = flag_str.width;
		while (str_len--)
			write(1, str++, 1);
		while (flag_str.width-- - cnt > 0)
			write(1, " ", 1);
		return (size);
	}
	return (0);
}
