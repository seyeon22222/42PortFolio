/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:07:27 by seykim            #+#    #+#             */
/*   Updated: 2023/05/17 21:20:12 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	else
		return (0);
}

int	ft_isspace(char *c)
{
	int	cnt_s;
	int	cnt_d;

	cnt_s = 0;
	cnt_d = 0;
	while (*c)
	{
		if (*c == 32)
			cnt_s++;
		if (ft_isdigit(*c))
			cnt_d++;
		c++;
	}
	if (((cnt_d == 0) && (cnt_s > 0)) || (cnt_d == 0))
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	if (cnt_s > 0)
		return (1);
	return (0);
}
