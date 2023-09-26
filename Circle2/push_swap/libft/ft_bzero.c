/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:27:54 by seykim            #+#    #+#             */
/*   Updated: 2023/03/14 12:09:58 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}
/*
#include <strings.h>
#include <stdio.h>
int main ()
{
    char a[] = "abcdefghjqkaieg";
    char b[] = "abcdefghjqkaieg";
    char c[] = "  1";
    char d[] = "  1";

    bzero(a, 5);
    ft_bzero(b, 5);
    printf("정답 : ");
    for (int i = 0; i < 16; i++)
    {
        printf("%c", a[i]);
    }
    printf("\n");
    printf("출력 : ");
    for (int i = 0; i < 16; i++)
    {
        printf("%c", b[i]);
    }
    printf("\n");
    printf("-------------------\n");
    bzero(c, 2);
    ft_bzero(d, 2);
    printf("정답 : ");
    for (int i = 0; i < 3; i++)
    {
        printf("%c", c[i]);
    }
    printf("\n");
    printf("출력 : ");
    for (int i = 0; i < 3; i++)
    {
        printf("%c", d[i]);
    }
    printf("\n");
    printf("-------------------\n");
    return (0);
}*/