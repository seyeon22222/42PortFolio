/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:59:46 by seykim            #+#    #+#             */
/*   Updated: 2023/11/23 20:53:48 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	camera_check(t_info **temp, char *arr, int idx)
{
	char	**split;
	int		num;

	num = 0;
	(*temp)->camera.num++;
	split = ft_split(arr, 32);
	while (split[idx])
	{
		if (idx == 1)
			camera_check2(split[idx], temp);
		else if (idx == 2)
			camera_check3(split[idx], temp);
		else if (idx == 3)
		{
			num = ft_atoi(split[idx]);
			if (num > 180 || num < 0)
				print_error("Camera FOV error");
			else
				(*temp)->camera.fov = num;
		}
		idx++;
	}
	free_split(split);
}

void	camera_check2(char *str, t_info **temp)
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
			(*temp)->camera.x = num;
		else if (idx == 1)
			(*temp)->camera.y = num;
		else if (idx == 2)
			(*temp)->camera.z = num;
		idx++;
	}
	free_split(split);
}

void	camera_check3(char *str, t_info **temp)
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
			print_error("Camera Vector error");
		else
		{
			if (idx == 0)
				(*temp)->camera.vector_x = num;
			else if (idx == 1)
				(*temp)->camera.vector_y = num;
			else if (idx == 2)
				(*temp)->camera.vector_z = num;
		}
		idx++;
	}
	free_split(split);
}
