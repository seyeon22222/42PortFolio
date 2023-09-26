/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:44:12 by seykim            #+#    #+#             */
/*   Updated: 2023/03/23 15:05:27 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_newstr(long long n, long long i, long long cnt, long long flag);
static void	*ft_calloc(size_t count, size_t size);

char	*ft_itoa(int n)
{
	long long	temp;
	long long	cnt;
	long long	result;
	long long	i;
	long long	flag;

	flag = 0;
	cnt = 0;
	temp = n;
	if (temp < 0)
	{
		flag = 1;
		temp *= -1;
	}
	result = temp;
	while (temp / 10 != 0)
	{
		temp = temp / 10;
		cnt++;
	}
	i = cnt;
	return (ft_newstr(result, i, cnt, flag));
}

static char	*ft_newstr(long long n, long long i, long long cnt, long long flag)
{
	char	*str;

	str = ft_calloc(sizeof(char), (cnt + flag + 1));
	if (!str)
		return (NULL);
	if (flag == 1)
		str[0] = '-';
	while (i > 0)
	{
		str[i + flag] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[i + flag] = n % 10 + '0';
	return (str);
}

static void	*ft_calloc(size_t count, size_t size)
{
	char	*newstr;
	size_t	i;

	i = 0;
	newstr = malloc(count * size + 1);
	if (newstr == NULL)
		return (NULL);
	while (i < (count * size))
	{
		newstr[i] = 0;
		i++;
	}
	newstr[i] = 0;
	return ((void *)newstr);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s \n", ft_itoa(-2147483647 - 1));
// 	return 0;
// }