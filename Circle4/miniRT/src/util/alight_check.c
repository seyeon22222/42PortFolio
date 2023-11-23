/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alight_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:59:46 by seykim            #+#    #+#             */
/*   Updated: 2023/11/23 20:00:05 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	alight_check(t_info **temp, char *arr, int idx)
{
	char	**split;
	int		num;

	num = 0;
	(*temp)->alight.num++;
	split = ft_split(arr, 32);
	while (split[idx])
	{
		if (idx == 1)
		{
			(*temp)->alight.ratio = ft_atof(split[idx]);
			if (!((*temp)->alight.ratio >= 0.0 \
			&& (*temp)->alight.ratio <= 1.0))
				print_error("Ratio error");
		}
		else if (idx == 2)
			alight_check2(split[idx], &num, temp);
		idx++;
	}
	free_split(split);
}

void	alight_check2(char *str, int *num, t_info **temp)
{
	char	**split;
	int		idx;

	split = ft_split(str, ',');
	idx = 0;
	while (split[idx])
	{
		*num = ft_atoi(split[idx]);
		if (*num < 0 || *num > 255)
			print_error("R,G,B range error");
		else
		{
			if (idx == 0)
				(*temp)->alight.r_range = *num;
			else if (idx == 1)
				(*temp)->alight.b_range = *num;
			else if (idx == 2)
				(*temp)->alight.g_range = *num;
		}
		idx++;
	}
	free_split(split);
}