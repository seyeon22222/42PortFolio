/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:47:56 by seykim            #+#    #+#             */
/*   Updated: 2023/03/21 20:44:05 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*newstr;
	size_t	i;

	i = 0;
	newstr = malloc(count * size);
	if (newstr == NULL)
		return (NULL);
	while (i < (count * size))
	{
		newstr[i] = 0;
		i++;
	}
	return ((void *)newstr);
}
