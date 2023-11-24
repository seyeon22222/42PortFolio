/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:23:06 by seykim            #+#    #+#             */
/*   Updated: 2023/11/24 14:46:16 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	light_check2(char *str, t_info **temp);
static void	light_check3(char *str, t_info **temp);

void	light_check(t_info **temp, char *arr, int idx)
{
	char	**split;
	float	num;

	num = 0;
	(*temp)->light.num++;
	if ((*temp)->light.num > 1)
		print_error("Light Num Error");
	split = ft_split(arr, 32);
	while (split[idx])
	{
		if (idx == 1)
			light_check2(split[idx], temp);
		else if (idx == 2)
		{
			num = ft_atof(split[idx]);
			if (num > 1 || num < 0)
				print_error("Light Ratio error");
			else
				(*temp)->light.ratio = num;
		}
		else if (idx == 3)
			light_check3(split[idx], temp);
		idx++;
	}
	free_split(split);
}

static void	light_check2(char *str, t_info **temp)
{
	char	**split;
	int		idx;
	float	num;

	split = ft_split(str, ',');
	idx = 0;
	while (split[idx])
	{
		num = ft_atof(split[idx]);
		if (idx == 0)
			(*temp)->light.x = num;
		else if (idx == 1)
			(*temp)->light.y = num;
		else if (idx == 2)
			(*temp)->light.z = num;
		idx++;
	}
	free_split(split);
}

static void	light_check3(char *str, t_info **temp)
{
	char	**split;
	int		idx;
	float	num;

	split = ft_split(str, ',');
	idx = 0;
	while (split[idx])
	{
		num = ft_atoi(split[idx]);
		if (num > 255 || num < 0)
			print_error("light R,G,B Range error");
		else
		{
			if (idx == 0)
				(*temp)->light.r_range = num;
			else if (idx == 1)
				(*temp)->light.g_range = num;
			else if (idx == 2)
				(*temp)->light.b_range = num;
		}
		idx++;
	}
	free_split(split);
}
