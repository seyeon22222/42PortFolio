/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:39:23 by seykim            #+#    #+#             */
/*   Updated: 2023/03/15 14:52:41 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				num;
	const unsigned char	*a;
	const unsigned char	*b;

	num = 0;
	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	while ((*a || *b) && (num < n))
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
		num++;
	}
	return (0);
}
