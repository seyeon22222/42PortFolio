/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:19:07 by seykim            #+#    #+#             */
/*   Updated: 2023/03/18 19:40:38 by seykim           ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	count;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	count = 0;
	if (dstsize < dst_len)
		return (src_len + dstsize);
	else if (dstsize > dst_len)
	{
		while (count + dst_len + 1 < dstsize && *src != 0)
		{
			dst[dst_len + count] = *src;
			count++;
			src++;
		}
		dst[dst_len + count] = 0;
		return (dst_len + src_len);
	}
	return (src_len + dstsize);
}
