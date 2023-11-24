/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:23:06 by seykim            #+#    #+#             */
/*   Updated: 2023/11/24 14:45:44 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	plane_check2(char *str, t_info **temp);
static void	plane_check3(char *str, t_info **temp);
static void	plane_check4(char *str, t_info **temp);

void	plane_check(t_info **temp, char *arr, int idx)
{
	char	**split;

	(*temp)->plane.num++;
	if ((*temp)->plane.num > 1)
		print_error("Plane Num Error");
	split = ft_split(arr, 32);
	while (split[idx])
	{
		if (idx == 1)
			plane_check2(split[idx], temp);
		else if (idx == 2)
			plane_check3(split[idx], temp);
		else if (idx == 3)
			plane_check4(split[idx], temp);
		idx++;
	}
	free_split(split);
}

static void	plane_check2(char *str, t_info **temp)
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
			(*temp)->plane.x = num;
		else if (idx == 1)
			(*temp)->plane.y = num;
		else if (idx == 2)
			(*temp)->plane.z = num;
		idx++;
	}
	free_split(split);
}

static void	plane_check3(char *str, t_info **temp)
{
	char	**split;
	int		idx;
	float	num;

	split = ft_split(str, ',');
	idx = 0;
	while (split[idx])
	{
		num = ft_atof(split[idx]);
		if (num > 1 || num < -1)
			print_error("Plane Vector Range error");
		else
		{
			if (idx == 0)
				(*temp)->plane.vector_x = num;
			else if (idx == 1)
				(*temp)->plane.vector_y = num;
			else if (idx == 2)
				(*temp)->plane.vector_z = num;
		}
		idx++;
	}
	free_split(split);
}

static void	plane_check4(char *str, t_info **temp)
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
			print_error("Plane R,G,B Range error");
		else
		{
			if (idx == 0)
				(*temp)->plane.r_range = num;
			else if (idx == 1)
				(*temp)->plane.g_range = num;
			else if (idx == 2)
				(*temp)->plane.b_range = num;
		}
		idx++;
	}
	free_split(split);
}
