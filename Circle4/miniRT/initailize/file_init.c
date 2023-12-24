/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:58:28 by seykim            #+#    #+#             */
/*   Updated: 2023/12/24 19:40:03 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "initailize.h"
#include "../figure/figure.h"

void	file_init(char **argv, t_obj_list *obj_list, t_info *info)
{
	int			fd;
	char		*arr;

	info->a_light_num = 0;
	info->light_num = 0;
	info->cam_num = 0;
	fd = open(argv[1], O_RDONLY);
	arr = get_next_line(fd);
	while (arr)
	{
		check_arr(arr, obj_list, info);
		free(arr);
		arr = get_next_line(fd);
	}
}

void	check_arr(char *arr, t_obj_list *temp, t_info *info)
{
	int		idx;

	idx = 1;
	if (arr[0] == 'A' && arr[1] == 32)
		alight_check(info, arr, idx);
	else if (arr[0] == 'C' && arr[1] == 32)
		camera_check(info, arr, idx);
	else if (arr[0] == 'L' && arr[1] == 32)
		light_check(info, arr, idx);
	else if (arr[0] == 's' && arr[1] == 'p' && arr[2] == 32)
		sphere_check(temp, arr, idx);
	else if (arr[0] == 'p' && arr[1] == 'l' && arr[2] == 32)
		plane_check(temp, arr, idx);
	else if (arr[0] == 'c' && arr[1] == 'y' && arr[2] == 32)
		cylinder_check(temp, arr, idx);
}
