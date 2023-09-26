/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:40:35 by seykim            #+#    #+#             */
/*   Updated: 2023/03/23 15:06:45 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*a;
	size_t				i;

	a = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*a == (unsigned char)c)
			return ((void *)a);
		a++;
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int main(void)
// {	
//     const char *str;
// 	const char *str2;
// 	str = ft_memchr("bonjourno", 'n', 5);
// 	str2 = memchr("bonjourno", 'n', 5);
// 	printf("%s\n",str);
// 	printf("%s\n",str2);
//     // int ch1 = 'p';
//     // int ch2 = 'z';
//     // int ch3 = 0;
//     // printf("------------------\n");
//     // printf("정답: %s\n", memchr(str, ch1, 10));
//     // printf("출력: %s\n", ft_memchr(str, ch1, 10));
//     // printf("------------------\n");
//     // printf("정답: %s\n", memchr(str, ch2, 10));
//     // printf("출력: %s\n", ft_memchr(str, ch2, 10));
//     // printf("------------------\n");
//     // printf("정답: %s\n", memchr(str, ch3, 10));
//     // printf("출력: %s\n", ft_memchr(str, ch3, 10));
//     // printf("------------------\n");
// }