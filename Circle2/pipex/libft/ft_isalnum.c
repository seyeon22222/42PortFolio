/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:26:54 by seykim            #+#    #+#             */
/*   Updated: 2023/03/13 14:38:54 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
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
        b = isalnum(a[i]);
        c = ft_isalnum(a[i]);
        printf("%d번째 정답 : %d\n",i ,b);
        printf("%d번째 출력 : %d\n",i, c);
    }
    return (0);
}
*/
