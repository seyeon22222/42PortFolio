/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:52:11 by seykim            #+#    #+#             */
/*   Updated: 2023/04/06 17:22:39 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_dec(va_list cur, int idx)
{
	int		num;
	char	num_str[11];
	int		flag;

	num = va_arg(cur, int);
	flag = 0;
	if (num == -2147483648)
		return (excp());
	if (num < 0)
	{
		num = -num;
		flag = 1;
	}
	str_add(num_str, &idx, num);
	if (flag == 1)
	{
		if (printf_char('-') < 0)
			return (-1);
	}
	while (num_str[++idx])
	{
		if (printf_char(num_str[idx]) < 0)
			return (-1);
	}
	return (idx + flag);
}

void	str_add(char *num_str, int *idx, int num)
{
	if (num == 0)
		num_str[(*idx)++] = num % 10 + '0';
	while (num != 0)
	{
		num_str[*idx] = num % 10 + '0';
		num /= 10;
		(*idx)++;
	}
	num_str[*idx] = 0;
	ft_strrev(num_str);
	*idx = -1;
}

int	excp(void)
{
	if (write(1, "-2147483648", 11) < 0)
		return (-1);
	return (11);
}

int	ft_putnbr_ui(unsigned int nb)
{
	unsigned int	num;
	unsigned int	size;
	int				temp;

	num = 0;
	size = 1;
	if (nb / 10 != 0)
	{
		temp = ft_putnbr_ui(nb / 10);
		if (temp < 0)
			return (temp);
		size += temp;
	}
	num = nb % 10;
	if (write (1, &"0123456789"[num], 1) < 0)
		return (-1);
	return (size);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
