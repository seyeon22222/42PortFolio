/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:19:12 by seykim            #+#    #+#             */
/*   Updated: 2023/03/31 14:48:53 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_s(va_list cur, t_flag flag_str)
{
	int		size;
	char	*str;

	size = 0;
	str = va_arg(cur, char *);
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	if (flag_str.zero == 0 && flag_str.shap == 0 \
	&& flag_str.space == 0 && flag_str.plus == 0)
	{
		if (flag_str.minus == 0)
			return (format_s_nominus(flag_str, str, size));
		else
			return (format_s_minus(flag_str, str, size));
	}
	return (0);
}

int	format_s_minus(t_flag flag_str, char *str, int size)
{
	if (flag_str.dot == 0)
		return (format_s_no_dot(flag_str, str, size));
	if (flag_str.width == 0 && flag_str.precision == 0)
		return (size);
	if (flag_str.precision < ft_strlen(str))
		return (format_strbig_minus(flag_str, str, size));
	else
		return (format_strbig_minus2(flag_str, str, size));
	return (0);
}

int	format_s_nominus(t_flag flag_str, char *str, int size)
{
	if (flag_str.dot == 0)
		return (format_s_no_dot(flag_str, str, size));
	if (flag_str.width == 0 && flag_str.precision == 0)
		return (size);
	if (flag_str.precision < ft_strlen(str))
		return (format_strbig_plus(flag_str, str, size));
	else
		return (format_strbig_plus2(flag_str, str, size));
}
