/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:35:41 by seykim            #+#    #+#             */
/*   Updated: 2023/03/23 15:09:54 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*b;

	b = NULL;
	while (*s)
	{
		if (*s == (char)c)
			b = s;
		s++;
	}
	if (*s == (char)c)
		b = s;
	if (b == NULL)
		return (NULL);
	return ((char *)b);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *src = "hello world \0abcdefgcdggddd\0";
// 	char *d1 = strrchr(src, '\0');
// 	char *d2 = ft_strrchr(src, '\0');

// 	printf("%s \n", d1);
// 	printf("%s \n", d2);
// }