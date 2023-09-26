/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:17:50 by seykim            #+#    #+#             */
/*   Updated: 2023/06/20 17:49:57 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	click_key(t_info *info)
{
	mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img);
	mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img2);
	mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img3);
	mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img4);
	mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img5);
	mlx_destroy_window(info->my_mlx->mlx, info->my_mlx->win);
	exit(0);
}
