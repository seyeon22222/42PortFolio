/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:59:46 by seykim            #+#    #+#             */
/*   Updated: 2023/12/24 19:39:53 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initailize.h"
#include "../figure/figure.h"
#include "../vector/vector.h"
#include "../view/view.h"

static void	camera_check2(char **split, int idx, t_info *temp);
static void	camera_check3(char *str, t_info *temp);
static void	camera_check4(char *str, t_info *temp);

void	camera_check(t_info *temp, char *arr, int idx)
{
	char		**split;

	temp->cam_num++;
	if (temp->cam_num > 1)
		print_error("Camera Num Error");
	split = ft_split(arr, 32);
	camera_check2(split, idx, temp);
	free_split(split);
}

static void	camera_check2(char **split, int idx, t_info *temp)
{
	int	num;

	num = 0;
	while (split[idx])
	{
		if (idx == 1)
			camera_check3(split[idx], temp);
		else if (idx == 2)
			camera_check4(split[idx], temp);
		else if (idx == 3)
		{
			num = ft_atoi(split[idx]);
			if (num > 180 || num < 0)
				print_error("Camera FOV error");
			else
				temp->cam.fov = num;
		}
		idx++;
	}
}

static void	camera_check3(char *str, t_info *temp)
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
			temp->cam.origin.x = num;
		else if (idx == 1)
			temp->cam.origin.y = num;
		else if (idx == 2)
			temp->cam.origin.z = num;
		idx++;
	}
	free_split(split);
}

static void	camera_check4(char *str, t_info *temp)
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
				temp->cam.dir.x = num;
			else if (idx == 1)
				temp->cam.dir.y = num;
			else if (idx == 2)
				temp->cam.dir.z = num;
		}
		idx++;
	}
	free_split(split);
}
