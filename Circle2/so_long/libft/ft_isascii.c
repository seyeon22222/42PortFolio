/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:41:41 by seykim            #+#    #+#             */
/*   Updated: 2023/03/13 15:07:09 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
    int a[6] = {0, 128, 64, 129, 100, 255};
    int b;
    int c;
    for (int i = 0; i <= 5; i++)
    {
        b = isascii(a[i]);
        c = ft_isascii(a[i]);
        printf("----------------------\n");
        printf("%d번째 정답 : %d\n",i ,b);
        printf("%d번째 출력 : %d\n",i, c);
        
    }
    return (0);
}
*/
