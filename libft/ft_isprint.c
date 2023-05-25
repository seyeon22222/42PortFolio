/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:07:27 by seykim            #+#    #+#             */
/*   Updated: 2023/03/13 15:13:18 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
    int a[6] = {9, 31, 126, 127, 128, 199};
    int b;
    int c;
    for (int i = 0; i <= 5; i++)
    {
        b = isprint(a[i]);
        c = ft_isprint(a[i]);
        printf("----------------------\n");
        printf("%d번째 정답 : %d\n",i ,b);
        printf("%d번째 출력 : %d\n",i, c);
    }
    return (0);
}
*/
