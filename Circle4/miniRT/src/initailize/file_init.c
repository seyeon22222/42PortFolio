/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:58:28 by seykim            #+#    #+#             */
/*   Updated: 2023/11/24 16:49:52 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_info	*file_init(char **argv)
{
	t_info	*temp;
	int		fd;
	char	*arr;

	temp = info_init();
	fd = open(argv[1], O_RDONLY);
	arr = get_next_line(fd);
	while (arr)
	{
		check_arr(arr, &temp);
		free(arr);
		arr = get_next_line(fd);
	}
	return (temp);
}

t_info	*info_init(void)
{
	t_info	*temp;

	temp = (t_info *)malloc(sizeof(t_info));
	if (!temp)
		print_error("Malloc Fail");
	temp->total_num = 0;
	alight_init(temp);
	camera_init(temp);
	cylinder_init(temp);
	light_init(temp);
	plane_init(temp);
	sphere_init(temp);
	return (temp);
}
