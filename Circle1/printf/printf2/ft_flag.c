/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:56:09 by seykim            #+#    #+#             */
/*   Updated: 2023/03/31 16:50:53 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	flag_init(void)
{
	t_flag	flag;

	flag.minus = 0;
	flag.plus = 0;
	flag.precision = 0;
	flag.shap = 0;
	flag.space = 0;
	flag.width = 0;
	flag.zero = 0;
	flag.dot = 0;
	return (flag);
}

int	printf_flag(const char *arr, va_list cur, t_flag flag_str)
{
	while (*arr)
	{
		if (*arr == '#')
			flag_str.shap = 1;
		else if (*arr == '0')
			flag_str.zero = 1;
		else if (*arr == ' ')
			flag_str.space = 1;
		else if (*arr == '-')
			flag_str.minus = 1;
		else if (*arr == '+')
			flag_str.plus = 1;
		else
			break ;
		arr++;
	}
	return (printf_width(arr, cur, flag_str));
}

int	printf_width(const char *arr, va_list cur, t_flag flag_str)
{
	int		size;
	char	*atoi_size;

	size = 0;
	if (*arr == '*')
	{
		flag_str.width = va_arg(cur, int);
		return (printf_precision(arr, cur, flag_str));
	}
	while (*arr != '\0' && *arr != '.' && (!(find_conversion(arr))))
	{
		size++;
		arr++;
	}
	if (*arr == '.')
		flag_str.dot = 1;
	atoi_size = (char *)malloc(sizeof(char) * size + 1);
	if (!atoi_size)
		return (-1);
	ft_strlcpy(atoi_size, (char *)(arr - size), size + 1);
	flag_str.width = ft_atoi(atoi_size);
	free(atoi_size);
	return (printf_precision(arr, cur, flag_str));
}

int	printf_precision(const char *arr, va_list cur, t_flag flag_str)
{
	int		size;
	char	*atoi_size2;

	size = 0;
	if (*(arr + 1) == '.')
	{
		flag_str.dot = 1;
		arr++;
	}
	while (*arr && (!(find_conversion(arr))))
	{
		size++;
		arr++;
	}
	atoi_size2 = (char *)malloc((sizeof(char) * size) + 1);
	if (!atoi_size2)
		return (-1);
	ft_memset(atoi_size2, 0, (sizeof(char) * size) + 1);
	ft_strlcpy(atoi_size2, (char *)(arr - size), size + 1);
	flag_str.precision = ft_atoi(atoi_size2);
	free(atoi_size2);
	return (printf_format(arr, cur, flag_str));
}
