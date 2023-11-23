/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:50:59 by seykim            #+#    #+#             */
/*   Updated: 2023/11/23 20:50:11 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_info	*info;

	arg_error(argc, argv);
	info = file_init(argv);
	// printf("%d\n", info->alight.num);
	// printf("%f\n", info->alight.ratio);
	// printf("%d\n", info->alight.r_range);
	// printf("%d\n", info->alight.b_range);
	// printf("%d\n", info->alight.g_range);
	printf("%f\n", info->camera.x);
	printf("%f\n", info->camera.y);
	printf("%f\n", info->camera.z);
	printf("%f\n", info->camera.vector_x);
	printf("%f\n", info->camera.vector_y);
	printf("%f\n", info->camera.vector_z);
	printf("%d\n", info->camera.fov);
}
