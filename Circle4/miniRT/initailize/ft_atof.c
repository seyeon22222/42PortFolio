/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:59:35 by seykim            #+#    #+#             */
/*   Updated: 2023/12/19 20:40:10 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initailize.h"

static void	make_float(char **str, float *num);

float	ft_atof(char *str)
{
	int		flag;
	float	num;
	char	**split;

	flag = 0;
	num = 0;
	if (str[0] == '-')
		flag = 1;
	if (flag == 1)
		split = ft_split(str + 1, '.');
	else
		split = ft_split(str, '.');
	make_float(split, &num);
	free_split(split);
	if (flag == 1)
		return (num * -1);
	else
		return (num);
}

static void	make_float(char **str, float *num)
{
	int		idx;
	int		idx2;
	float	num_square;

	idx = 0;
	num_square = 0.1;
	while (str[idx])
	{
		if (idx == 0)
			*num += ft_atoi(str[idx]);
		else if (idx == 1)
		{
			idx2 = 0;
			while (str[idx][idx2])
			{
				*num += ((str[idx][idx2] - '0') * num_square);
				num_square *= 0.1;
				idx2++;
			}
		}
		idx++;
	}
}
