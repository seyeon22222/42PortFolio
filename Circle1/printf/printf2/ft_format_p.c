/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:53:12 by seykim            #+#    #+#             */
/*   Updated: 2023/03/31 16:44:19 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_p(va_list cur, t_flag flag_str)
{
	if (flag_str.precision == 0 && flag_str.minus == 0 \
	&& flag_str.zero == 0 && flag_str.shap == 0 \
	&& flag_str.space == 0 && flag_str.plus == 0)
	{
		if (flag_str.width > 14)
		{
			if (flag_str.minus == 1)
				return (format_p_minus(cur, flag_str));
			else
				return (format_p_nominus(cur, flag_str));
		}
		else
		{
			write (1, "0x", 2);
			return (format_p_w(cur, 0) + 2);
		}
	}
	return (-1);
}

int	format_p_w(va_list cur, int idx)
{
	unsigned long	num;
	char			*base;
	char			num_str[17];

	num = (unsigned long)va_arg(cur, void *);
	base = "0123456789abcdef";
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
		write (1, &num_str[idx], 1);
	return (idx);
}

int	format_p_minus(va_list cur, t_flag flag_str)
{
	int	size;

	write (1, "0x", 2);
	size = format_p_w(cur, 0) + 2;
	while (flag_str.width - 14)
	{
		write(1, " ", 1);
		flag_str.width--;
	}
	return (size);
}

int	format_p_nominus(va_list cur, t_flag flag_str)
{
	while (flag_str.width - 14)
	{
		write(1, " ", 1);
		flag_str.width--;
	}
	write (1, "0x", 2);
	return (format_p_w(cur, 0) + 2);
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
