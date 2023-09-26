/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:13:48 by seykim            #+#    #+#             */
/*   Updated: 2023/03/17 13:36:14 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	idx;

	new_str = (char *)malloc(sizeof(char) * \
	(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	idx = 0;
	while (idx < ft_strlen(s1) + ft_strlen(s2))
	{
		if (idx < ft_strlen(s1))
		{
				new_str[idx] = s1[idx];
				idx++;
		}
		else if (idx >= ft_strlen(s1) && idx < ft_strlen(s1) + ft_strlen(s2))
		{
				new_str[idx] = s2[idx - ft_strlen(s1)];
				idx++;
		}
	}
	new_str[idx] = 0;
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
