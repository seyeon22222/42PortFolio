/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:13:36 by seykim            #+#    #+#             */
/*   Updated: 2023/03/14 12:09:27 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
/*
#include <stdio.h>
int main ()
{
    char *s = "123456789";
    char *b = "asdqwezxcjkl";
    char *a = 0;

    printf("정답 : %ld\n", strlen(s));
    printf("출력 : %lu\n", ft_strlen(s));
    printf("----------------------\n");
    printf("정답 : %lu\n", strlen(b));
    printf("출력 : %lu\n", ft_strlen(b));
    printf("----------------------\n");
    printf("정답 : %lu\n", strlen(a));
    printf("출력 : %lu\n", ft_strlen(a));
}
*/