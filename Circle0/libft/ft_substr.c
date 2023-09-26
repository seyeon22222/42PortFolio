/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:25:01 by seykim            #+#    #+#             */
/*   Updated: 2023/03/20 18:23:55 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	int		i;

	i = 0;
	if ((len == 0 || start > (unsigned int)ft_strlen(s)))
	{
		new_str = malloc(1);
		if (!new_str)
			return (NULL);
		*new_str = 0;
		return (new_str);
	}
	if ((len + start > (unsigned int)ft_strlen(s)))
		new_str = (char *)malloc(sizeof(char) * ((ft_strlen(s) - start + 1)));
	else
		new_str = (char *)malloc((sizeof(char) * len) + 1);
	if (!new_str)
		return (NULL);
	while (s[start] && len--)
		new_str[i++] = s[start++];
	new_str[i] = 0;
	return (new_str);
}

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
/*
s: The string from which to create the substring.
start: The start index of the substring in the
string ’s’.
len: The maximum length of the substring.
The substring.
NULL if the allocation fails.
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
*/