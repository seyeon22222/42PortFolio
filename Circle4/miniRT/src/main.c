/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:50:59 by seykim            #+#    #+#             */
/*   Updated: 2023/11/24 19:46:09 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 순서
// 1. 픽셀로 그림그리기
// 2. 카메라 레이 구현하기(좌표 -> 시작점 , 위치 있으면 구현됨)
// 3. 카메라 구현
// 4. 도형하나 그려보기

#include "../include/minirt.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_info	*info;

	arg_error(argc, argv);
	info = file_init(argv);
	printf("%d\n", info->alight.num);
	printf("%d\n", info->light.num);
	printf("%d\n", info->camera.num);
	printf("%d\n", info->sphere.num);
	printf("%d\n", info->cylinder.num);
	printf("%d\n", info->plane.num);
	info->my_mlx = my_mlx_init(1024, 1024, info->total_num, info);
	// mlx_hook(info->my_mlx->win, X_EVENT_KEY_PRESS, 0, &key_press, info);
	// mlx_hook(info->my_mlx->win, X_EVENT_MOUSE_EXIT, 0, &click_key, info);
	// mlx_loop(info->my_mlx);
	free(info);
}
