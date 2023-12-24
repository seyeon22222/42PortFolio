/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:32:36 by seykim            #+#    #+#             */
/*   Updated: 2023/12/19 14:58:07 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	idx;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen1(s1);
	len2 = ft_strlen1(s2);
	new_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new_str)
		return (ft_free(&s1));
	idx = -1;
	while (++idx < len1 + len2)
	{
		if (idx < len1)
			new_str[idx] = s1[idx];
		else if ((idx >= len1) && idx < (len1 + len2))
			new_str[idx] = s2[idx - len1];
	}
	new_str[idx] = 0;
	ft_free(&s1);
	return (new_str);
}

size_t	ft_strlen1(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*new_str;
	int		i;

	i = 0;
	if ((len == 0 || start > (unsigned int)ft_strlen1(s)))
	{
		new_str = malloc(1);
		if (!new_str)
			return (0);
		*new_str = 0;
		return (new_str);
	}
	if ((len + start > (unsigned int)ft_strlen1(s)))
		new_str = (char *)malloc(sizeof(char) * ((ft_strlen1(s) - start + 1)));
	else
		new_str = (char *)malloc((sizeof(char) * len) + 1);
	if (!new_str)
		return (0);
	while (s[start] && len--)
		new_str[i++] = s[start++];
	new_str[i] = 0;
	return (new_str);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	int		num;
	char	*src_cpy;

	num = 0;
	src_len = 0;
	if (!src)
		return (0);
	while (src[src_len])
		src_len++;
	src_cpy = (char *)malloc(sizeof(char) * src_len + 1);
	if (src_cpy == 0)
		return (0);
	while (src[num])
	{
		src_cpy[num] = src[num];
		num++;
	}
	src_cpy[num] = 0;
	return (src_cpy);
}
