/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:54:06 by seykim            #+#    #+#             */
/*   Updated: 2023/03/14 20:54:10 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		src_len;
	int		num;
	char	*src_cpy;

	num = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	src_cpy = (char *)malloc(sizeof(char) * src_len + 1);
	if (src_cpy == NULL)
		return (NULL);
	while (src[num])
	{
		src_cpy[num] = src[num];
		num++;
	}
	src_cpy[num] = 0;
	return (src_cpy);
}
