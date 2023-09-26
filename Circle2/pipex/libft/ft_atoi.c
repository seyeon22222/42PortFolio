/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:08:19 by seykim            #+#    #+#             */
/*   Updated: 2023/05/12 05:50:50 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int	excp_long(const char *str, int minus, long long val);
static int	sign_val(const char **str, int minus);

int	ft_atoi(const char *str)
{
	int			minus;
	long long	val;

	minus = sign_val(&str, 0);
	val = 0;
	while (*str >= 48 && *str <= 57)
	{
		if ((excp_long(str, minus, val) == -1))
			return (0);
		if ((excp_long(str, minus, val) == 1))
			return (-1);
		val = val * 10 + *str++ - 48;
	}
	if (minus == 1)
		val = -val;
	if (*str != '\0' || val > 2147483647 || val < -2147483648)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return ((int)val);
}

static int	sign_val(const char **str, int minus)
{
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	if (**str == 45 || **str == 43)
	{
		if (**str == 45)
			minus = 1;
		(*str)++;
	}
	return (minus);
}

static int	excp_long(const char *str, int minus, long long val)
{
	if (val >= 922337203685477580 && minus == 1 && *str == 57)
		return (-1);
	else if (val > 922337203685477580 && minus == 1)
		return (-1);
	else if (val >= 922337203685477580 && minus == 0 \
	&& (*str >= 56 && *str <= 57))
		return (1);
	else if (val > 922337203685477580 && minus == 0)
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// int main()
// {
// 	printf("my  : %d \n", ft_atoi("214748364800190000000000000"));
// 	printf("com : %d \n", atoi("214748364800190000000000000"));
// 	return 0;
// }