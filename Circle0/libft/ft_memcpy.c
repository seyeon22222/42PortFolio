/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:10:41 by seykim            #+#    #+#             */
/*   Updated: 2023/03/23 14:21:12 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*new_str;
	const char	*str;
	size_t		i;

	if ((dst == NULL) && (src == NULL))
		return (NULL);
	new_str = dst;
	str = src;
	i = 0;
	while (i < n)
	{
		new_str[i] = str[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// int main()
// {
//     char str[] = "abcdeasd";
//     char *str_ptr = str;
//     char *str_ptr2 = str+2;
//     //printf("%p \n", str_ptr+2);
//     //printf("%p \n", str_ptr2);
//     memcpy(str_ptr2,str_ptr,4);
//     //ft_memcpy(str_ptr2,str_ptr,4);
//     printf("src: ");
//     for(int i =0; i < 8; i++)
//     {
//         printf("%c", str_ptr[i]);
//     }
//     printf("\ndst: ");
//     for(int i =0; i < 6; i++)
//     {
//         printf("%c", str_ptr2[i]);
//     }
//     printf("\n--------------\n");
//     return 0;
// }
