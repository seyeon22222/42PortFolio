/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:23:06 by seykim            #+#    #+#             */
/*   Updated: 2023/11/24 14:46:59 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	sphere_check2(char *str, t_info **temp);
static void	sphere_check3(char *str, t_info **temp);

void	sphere_check(t_info **temp, char *arr, int idx)
{
	char	**split;

	(*temp)->sphere.num++;
	if ((*temp)->sphere.num > 1)
		print_error("Sphere Num Error");
	split = ft_split(arr, 32);
	while (split[idx])
	{
		if (idx == 1)
			sphere_check2(split[idx], temp);
		else if (idx == 2)
			(*temp)->sphere.radius = ft_atof(split[idx]);
		else if (idx == 3)
			sphere_check3(split[idx], temp);
		idx++;
	}
	free_split(split);
}

static void	sphere_check2(char *str, t_info **temp)
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
			(*temp)->sphere.x = num;
		else if (idx == 1)
			(*temp)->sphere.y = num;
		else if (idx == 2)
			(*temp)->sphere.z = num;
		idx++;
	}
	free_split(split);
}

static void	sphere_check3(char *str, t_info **temp)
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
			print_error("Sphere R,G,B Range error");
		else
		{
			if (idx == 0)
				(*temp)->sphere.r_range = num;
			else if (idx == 1)
				(*temp)->sphere.g_range = num;
			else if (idx == 2)
				(*temp)->sphere.b_range = num;
		}
		idx++;
	}
	free_split(split);
}
