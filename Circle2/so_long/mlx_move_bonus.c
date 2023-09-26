/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:24:53 by seykim            #+#    #+#             */
/*   Updated: 2023/06/12 14:56:52 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_press_bonus(int keycode, t_info *info)
{
	info->flag = 0;
	if (keycode == KEY_W)
		move_w_bonus(info);
	else if (keycode == KEY_S)
		move_s_bonus(info);
	else if (keycode == KEY_A)
		move_a_bonus(info);
	else if (keycode == KEY_D)
		move_d_bonus(info);
	if (keycode == KEY_ESC)
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
	return (0);
}

void	move_w_bonus(t_info *info)
{
	if (info->visited[(info->char_row) - 1][info->char_col] == 'C')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[(info->char_row) - 1][info->char_col] = '0';
		info->visited[(info->char_row) - 1][info->char_col] = 'P';
		info->get_cnt++;
		info->char_row--;
		print_move_bonus(info, 0);
	}
	else if (info->visited[(info->char_row) - 1][info->char_col] == 'E' \
	&& info->get_cnt == info->item_cnt)
		print_move_bonus(info, 1);
	else if (info->visited[(info->char_row) - 1][info->char_col] == 'A')
		print_move_bonus(info, 1);
	else if (info->visited[(info->char_row) - 1][info->char_col] != '1' \
	&& info->visited[(info->char_row) - 1][info->char_col] != 'E')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[(info->char_row) - 1][info->char_col] = '0';
		info->visited[(info->char_row) - 1][info->char_col] = 'P';
		info->char_row--;
		print_move_bonus(info, 0);
	}
	move_enemy(info, -1, -1, 0);
	my_mlx_print_bonus(info->visited, info, -1, -1);
}

void	move_s_bonus(t_info *info)
{
	if (info->visited[(info->char_row) + 1][info->char_col] == 'C')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[(info->char_row) + 1][info->char_col] = '0';
		info->visited[(info->char_row) + 1][info->char_col] = 'P';
		info->get_cnt++;
		info->char_row++;
		print_move_bonus(info, 0);
	}
	else if (info->visited[(info->char_row) + 1][info->char_col] == 'E' \
	&& info->get_cnt == info->item_cnt)
		print_move_bonus(info, 1);
	else if (info->visited[(info->char_row) + 1][info->char_col] == 'A')
		print_move_bonus(info, 1);
	else if (info->visited[(info->char_row) + 1][info->char_col] != '1' \
	&& info->visited[(info->char_row) + 1][info->char_col] != 'E')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[(info->char_row) + 1][info->char_col] = '0';
		info->visited[(info->char_row) + 1][info->char_col] = 'P';
		info->char_row++;
		print_move_bonus(info, 0);
	}
	move_enemy(info, -1, -1, 1);
	my_mlx_print_bonus(info->visited, info, -1, -1);
}

void	move_a_bonus(t_info *info)
{
	if (info->visited[(info->char_row)][(info->char_col) - 1] == 'C')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[info->char_row][(info->char_col) - 1] = '0';
		info->visited[info->char_row][(info->char_col) - 1] = 'P';
		info->get_cnt++;
		info->char_col--;
		print_move_bonus(info, 0);
	}
	else if (info->visited[info->char_row][(info->char_col) - 1] == 'E' \
	&& info->get_cnt == info->item_cnt)
		print_move_bonus(info, 1);
	else if (info->visited[info->char_row][(info->char_col) - 1] == 'A')
		print_move_bonus(info, 1);
	else if (info->visited[info->char_row][(info->char_col) - 1] != '1' \
	&& info->visited[info->char_row][(info->char_col) - 1] != 'E')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[info->char_row][(info->char_col) - 1] = '0';
		info->visited[info->char_row][(info->char_col) - 1] = 'P';
		info->char_col--;
		print_move_bonus(info, 0);
	}
	move_enemy(info, -1, -1, 0);
	my_mlx_print_bonus(info->visited, info, -1, -1);
}

void	move_d_bonus(t_info *info)
{
	if (info->visited[(info->char_row)][(info->char_col) + 1] == 'C')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[info->char_row][(info->char_col) + 1] = '0';
		info->visited[info->char_row][(info->char_col) + 1] = 'P';
		info->get_cnt++;
		info->char_col++;
		print_move_bonus(info, 0);
	}
	else if (info->visited[info->char_row][(info->char_col) + 1] == 'E' \
	&& info->get_cnt == info->item_cnt)
		print_move_bonus(info, 1);
	else if (info->visited[info->char_row][(info->char_col) + 1] == 'A')
		print_move_bonus(info, 1);
	else if (info->visited[info->char_row][(info->char_col) + 1] != '1' \
	&& info->visited[info->char_row][(info->char_col) + 1] != 'E')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[info->char_row][(info->char_col) + 1] = '0';
		info->visited[info->char_row][(info->char_col) + 1] = 'P';
		info->char_col++;
		print_move_bonus(info, 0);
	}
	move_enemy(info, -1, -1, 1);
	my_mlx_print_bonus(info->visited, info, -1, -1);
}
