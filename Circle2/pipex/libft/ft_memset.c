/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:21:33 by seykim            #+#    #+#             */
/*   Updated: 2023/03/23 14:41:23 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = b;
	while (i < len)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (a);
}
// #include<string.h>
// #include<stdio.h>
// int main(void)
// {
//     char arr1[16] = "blockdmask blog";
//     char arr2[16] = "blockdmask blog";
//     char arr3[5] = "    1";
//     char arr4[5] = "    1";
//     char arr5[1] = "";
//     char arr6[1] = "";
//     memset(arr1, 'c', 16 * sizeof(char));
//     ft_memset(arr2, 'b', 16 * sizeof(char));
//     printf("정답 : ");
//     for (int i = 0; i < 17; i++)
//     {
//         printf("%c" , arr1[i]);
//     }
//     printf("\n");
//     printf("출력 : ");
//     for (int i = 0; i < 17; i++)
//     {
//         printf("%c" , arr2[i]);
//     }
//     printf("\n");
//     printf("----------------\n");
//     memset(arr3, 'c', 0 * sizeof(char));
//     ft_memset(arr4, 'a', 0 * sizeof(char));
//     printf("정답 : ");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%c" , arr3[i]);
//     }
//     printf("\n");
//     printf("출력 : ");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%c" , arr4[i]);
//     }
//     printf("\n");
//     printf("----------------\n");
//     memset(arr5, 'c', 1 * sizeof(char));
//     ft_memset(arr6, 'c', 1 * sizeof(char));
//     for (int i = 0; i < 1; i++)
//     {
//         printf("정답 : %c\n" , arr5[i]);
//         printf("출력 : %c\n" , arr6[i]);
//     }
//     int a[10] = {1,};
//     int b[10] = {1,};
//     memset(a,1,40);
//     ft_memset(b,1,40);
//     for (int i = 0; i < 10; i++)
//     {
//         printf("본래 함수 정답 : %d\n" , a[i]);
//         printf("내 출력 : %d\n" , b[i]);
//     }
//     return 0;
// }