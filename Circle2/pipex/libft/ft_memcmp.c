/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:56:32 by seykim            #+#    #+#             */
/*   Updated: 2023/03/15 15:09:06 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	char *s1 = "atoms\0\0\0\0";
// 	char *s2 = "atoms\0abc";
// 	size_t size = 8;
// 	int i1 = memcmp(s1, s2, size);
// 	int i2 = ft_memcmp(s1, s2, size);
// 	printf("%d \n", i1);
// 	printf("%d \n", i2);
// }
