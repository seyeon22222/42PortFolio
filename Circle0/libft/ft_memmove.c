/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:54:18 by seykim            #+#    #+#             */
/*   Updated: 2023/03/23 14:20:39 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*new_str;
	char const	*str;

	if ((dst == NULL) && (src == NULL))
		return (NULL);
	new_str = dst;
	str = src;
	if (new_str > str)
	{
		while (len-- > 0)
			new_str[len] = str[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			new_str[i] = str[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{	
	//printf("%p \n",memmove(((void *)0), "segfaulter tu dois", 3));
	printf("%p \n",ft_memmove(((void *)0), "segfaulter tu dois", 3));
}*/

// #include <stdio.h>
// int main()
// {
//     char str[] = "abcdeasd";
//     char *str_ptr = str;
//     char *str_ptr2 = str+2;
//     //printf("%p \n", str_ptr+2);
//     //printf("%p \n", str_ptr2);
//     //memmove(str_ptr2,str_ptr,4);
//     ft_memmove(str_ptr2,str_ptr,4);
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