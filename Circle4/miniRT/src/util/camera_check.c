/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:59:46 by seykim            #+#    #+#             */
/*   Updated: 2023/11/27 19:40:46 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	camera_check2(char **split, int idx, t_camera *camera_temp);
static void	camera_check3(char *str, t_camera *temp);
static void	camera_check4(char *str, t_camera *temp);

void	camera_check(t_list *temp, char *arr, int idx)
{
	char		**split;
	t_camera	*camera_temp;

	camera_temp = (t_camera *)malloc(sizeof(t_camera));
	if (!camera_temp)
		print_error("No space to malloc camera");
	camera_init(camera_temp);
	camera_temp->num++;
	if (camera_temp->num > 1)
		print_error("Camera Num Error");
	split = ft_split(arr, 32);
	camera_check2(split, idx, camera_temp);
	free_split(split);
	if (!temp->content)
	{
		ft_lstdelone(temp, free);
		temp = ft_lstnew(camera_temp, camera);
	}
	else
		ft_lstadd_back(&temp, ft_lstnew(camera_temp, camera));
}

static void	camera_check2(char **split, int idx, t_camera *camera_temp)
{
	int	num;

	num = 0;
	while (split[idx])
	{
		if (idx == 1)
			camera_check3(split[idx], camera_temp);
		else if (idx == 2)
			camera_check4(split[idx], camera_temp);
		else if (idx == 3)
		{
			num = ft_atoi(split[idx]);
			if (num > 180 || num < 0)
				print_error("Camera FOV error");
			else
				camera_temp->fov = num;
		}
		idx++;
	}
}

static void	camera_check3(char *str, t_camera *temp)
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
			temp->x = num;
		else if (idx == 1)
			temp->y = num;
		else if (idx == 2)
			temp->z = num;
		idx++;
	}
	free_split(split);
}

static void	camera_check4(char *str, t_camera *temp)
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
				temp->cam_v.x = num;
			else if (idx == 1)
				temp->cam_v.y = num;
			else if (idx == 2)
				temp->cam_v.z = num;
		}
		idx++;
	}
	free_split(split);
}
