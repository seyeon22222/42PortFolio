/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:23:06 by seykim            #+#    #+#             */
/*   Updated: 2023/11/24 15:01:34 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	cylinder_check2(char *str, t_info **temp);
static void	cylinder_check3(char *str, t_info **temp);
static void	cylinder_check4(char *str, t_info **temp);

void	cylinder_check(t_info **temp, char *arr, int idx)
{
	char	**split;
	int		num;

	num = 0;
	(*temp)->cylinder.num++;
	if ((*temp)->cylinder.num > 1)
		print_error("Cylinder Num Error");
	split = ft_split(arr, 32);
	while (split[idx])
	{
		if (idx == 1)
			cylinder_check2(split[idx], temp);
		else if (idx == 2)
			cylinder_check3(split[idx], temp);
		else if (idx == 3)
			(*temp)->cylinder.delimeter = ft_atof(split[idx]);
		else if (idx == 4)
			(*temp)->cylinder.height = ft_atof(split[idx]);
		else if (idx == 5)
			cylinder_check4(split[idx], temp);
		idx++;
	}
	free_split(split);
}

static void	cylinder_check2(char *str, t_info **temp)
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
			(*temp)->cylinder.x = num;
		else if (idx == 1)
			(*temp)->cylinder.y = num;
		else if (idx == 2)
			(*temp)->cylinder.z = num;
		idx++;
	}
	free_split(split);
}

static void	cylinder_check3(char *str, t_info **temp)
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
			print_error("Cylinder Vector Range error");
		else
		{
			if (idx == 0)
				(*temp)->cylinder.vector_x = num;
			else if (idx == 1)
				(*temp)->cylinder.vector_y = num;
			else if (idx == 2)
				(*temp)->cylinder.vector_z = num;
		}
		idx++;
	}
	free_split(split);
}

static void	cylinder_check4(char *str, t_info **temp)
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
			print_error("Cylinder R,G,B Range error");
		else
		{
			if (idx == 0)
				(*temp)->cylinder.r_range = num;
			else if (idx == 1)
				(*temp)->cylinder.g_range = num;
			else if (idx == 2)
				(*temp)->cylinder.b_range = num;
		}
		idx++;
	}
	free_split(split);
}
