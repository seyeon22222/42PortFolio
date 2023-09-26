/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:17:50 by seykim            #+#    #+#             */
/*   Updated: 2023/06/12 14:54:25 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	my_mlx_print_bonus2(char **arr2, t_info *info, int i, int i2)
{
	if (arr2[i][i2] == 'C')
		mlx_put_image_to_window(info->my_mlx->mlx, info->my_mlx->win, \
		info->my_mlx->img3, i2 * 32, i * 32);
	else if (arr2[i][i2] == 'P' && info->char_num == 0)
		mlx_put_image_to_window(info->my_mlx->mlx, info->my_mlx->win, \
		info->my_mlx->img4, i2 * 32, i * 32);
	else if (arr2[i][i2] == 'P' && info->char_num == 1)
		mlx_put_image_to_window(info->my_mlx->mlx, info->my_mlx->win, \
		info->my_mlx->img6, i2 * 32, i * 32);
	else if (arr2[i][i2] == 'E' && info->get_cnt != info->item_cnt)
		mlx_put_image_to_window(info->my_mlx->mlx, info->my_mlx->win, \
		info->my_mlx->img5, i2 * 32, i * 32);
	else if (arr2[i][i2] == 'E' && info->get_cnt == info->item_cnt)
		mlx_put_image_to_window(info->my_mlx->mlx, info->my_mlx->win, \
		info->my_mlx->img7, i2 * 32, i * 32);
}

int	click_key_bonus(t_info *info)
{
	mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img);
	mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img1);
	mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img2);
	mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img3);
	mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img4);
	mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img5);
	mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img6);
	mlx_destroy_window(info->my_mlx->mlx, info->my_mlx->win);
	exit(0);
}

void	move_enemy(t_info *info, int i, int i2, int k)
{
	info->char_num = k;
	while (info->visited[++i] && i < info->size_row)
	{
		i2 = -1;
		move_enemy2(info, i, i2);
		info->flag = 0;
	}
}

void	move_enemy2(t_info *info, int i, int i2)
{
	while (info->visited[i][++i2] && i2 < info->size_col)
	{
		if (info->go_cnt % 2 == 0 && info->flag == 0)
		{
			if (info->visited[i][i2] == 'A' && info->visited[i][i2 + 1] == '0')
			{
				info->flag = 1;
				info->visited[i][i2] = '0';
				info->visited[i][i2 + 1] = 'A';
				break ;
			}
		}
		else if (info->go_cnt % 2 == 1 && info->flag == 0)
		{
			if (info->visited[i][i2] == 'A' && info->visited[i][i2 - 1] == '0')
			{
				info->flag = 1;
				info->visited[i][i2] = '0';
				info->visited[i][i2 - 1] = 'A';
				break ;
			}
		}
	}	
}
