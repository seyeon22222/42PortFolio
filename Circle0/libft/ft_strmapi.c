/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:37:43 by seykim            #+#    #+#             */
/*   Updated: 2023/03/23 14:41:02 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	newstr = malloc(sizeof(char) * len + 1);
	if (!newstr)
		return (NULL);
	while (i < len)
	{
		newstr[i] = (*f)(i, s[i]);
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}
