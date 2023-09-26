/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:13:50 by seykim            #+#    #+#             */
/*   Updated: 2023/03/22 17:30:40 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	while (i < len)
	{
		(*f)(i, s);
		i++;
		s++;
	}
	return ((void *)s);
}
