/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:39:35 by seykim            #+#    #+#             */
/*   Updated: 2023/03/13 14:37:03 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
    int a[6] = {48, 57, 65, 90, 97, 122};
    int b;
    int c;
    for (int i = 0; i <= 5; i++)
    {
        b = isalpha(a[i]);
        c = ft_isalpha(a[i]);
        printf("%d번째 정답 : %d\n",i ,b);
        printf("%d번째 출력 : %d\n",i, c);
    }
    return (0);
}
*/