/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:50:59 by seykim            #+#    #+#             */
/*   Updated: 2023/11/27 20:33:28 by seykim           ###   ########.fr       */
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
	t_list	*info;
	t_mlx	*my_mlx;

	arg_error(argc, argv);
	info = file_init(argv);
	my_mlx = my_mlx_init(1024, 1024, info);
	mlx_hook(my_mlx->win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, my_mlx);
	mlx_hook(my_mlx->win, X_EVENT_KEY_RELEASE, 1L << 1, &key_release, my_mlx);
	mlx_hook(my_mlx->win, X_EVENT_MOUSE_EXIT, 0, &click_key, my_mlx);
	mlx_loop(my_mlx->mlx);
	// t_list	*del_temp = info;
	while (info)
	{
		// 타입에 맞는 그리는 함수 호출
		if (info->figure == alight)
			printf("%d\n", ((t_alight *)(info->content))->num);
		else if (info->figure == camera)
			printf("%d\n", ((t_camera *)(info->content))->fov);
		else if (info->figure == light)
			printf("%d\n", ((t_light *)(info->content))->num);
		else if (info->figure == sphere)
			printf("%f\n", ((t_sphere *)(info->content))->radius);
		else if (info->figure == plane)
			printf("%d\n", ((t_plane *)(info->content))->r_range);
		else if (info->figure == cylinder)
			printf("%f\n", ((t_cylinder *)(info->content))->delimeter);
		info = info->next;
	}
	// ft_lstclear(&del_temp, free);
	// system("leaks miniRT");
}
