/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:16:43 by seykim            #+#    #+#             */
/*   Updated: 2023/03/18 19:40:46 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	real_n;
	size_t	src_len;

	real_n = 0;
	src_len = ft_strlen(src);
	if (src == 0 || size == 0)
		return (src_len);
	while (real_n < size -1 && src[real_n])
	{
		dest[real_n] = src[real_n];
		real_n++;
	}
	dest[real_n] = 0;
	while (src[real_n])
		real_n++;
	return (real_n);
}
