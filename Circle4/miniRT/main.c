/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:33:43 by seykim            #+#    #+#             */
/*   Updated: 2023/12/24 19:39:02 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "vector/vector.h"
#include "view/view.h"
#include "figure/figure.h"
#include "initailize/initailize.h"

int	main(int argc, char **argv)
{
	t_mlx		my_mlx;
	t_camera	cam;
	t_obj_list	*world;
	t_info		*info;

	arg_error(argc, argv);
	world = (t_obj_list *)malloc(sizeof(t_obj_list));
	if (!world)
		print_error("No space to Malloc");
	world->next = 0;
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		print_error("No space to Malloc");
	file_init(argv, world, info);
	cam = init_camera(info->cam);
	my_mlx.mlx = mlx_init();
	my_mlx.win = mlx_new_window(my_mlx.mlx, WIDTH, HEIGHT, "miniRT");
	my_mlx.data.img = mlx_new_image(my_mlx.mlx, WIDTH, HEIGHT);
	my_mlx.data.addr = mlx_get_data_addr(my_mlx.data.img, \
	&my_mlx.data.bits_per_pixel, &my_mlx.data.line_length, &my_mlx.data.endian);
	raytracing(&cam, world, &my_mlx, info);
	mlx_key_hook(my_mlx.win, key_hook, &my_mlx);
	mlx_loop(my_mlx.mlx);
}
