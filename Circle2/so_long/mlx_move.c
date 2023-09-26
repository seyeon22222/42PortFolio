/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:24:53 by seykim            #+#    #+#             */
/*   Updated: 2023/06/12 14:57:00 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_info *info)
{
	if (keycode == KEY_W)
		move_w(info);
	else if (keycode == KEY_S)
		move_s(info);
	else if (keycode == KEY_A)
		move_a(info);
	else if (keycode == KEY_D)
		move_d(info);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img);
		mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img2);
		mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img3);
		mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img4);
		mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img5);
		mlx_destroy_window(info->my_mlx->mlx, info->my_mlx->win);
		exit(0);
	}
	return (0);
}

void	move_w(t_info *info)
{
	if (info->visited[(info->char_row) - 1][info->char_col] == 'C')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[(info->char_row) - 1][info->char_col] = '0';
		info->visited[(info->char_row) - 1][info->char_col] = 'P';
		info->get_cnt++;
		info->char_row--;
		print_move(info, 0);
	}
	else if (info->visited[(info->char_row) - 1][info->char_col] == 'E' \
	&& info->get_cnt == info->item_cnt)
		print_move(info, 1);
	else if (info->visited[(info->char_row) - 1][info->char_col] != '1' \
	&& info->visited[(info->char_row) - 1][info->char_col] != 'E')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[(info->char_row) - 1][info->char_col] = '0';
		info->visited[(info->char_row) - 1][info->char_col] = 'P';
		info->char_row--;
		print_move(info, 0);
	}
	my_mlx_print(info->visited, info->my_mlx);
}

void	move_s(t_info *info)
{
	if (info->visited[(info->char_row) + 1][info->char_col] == 'C')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[(info->char_row) + 1][info->char_col] = '0';
		info->visited[(info->char_row) + 1][info->char_col] = 'P';
		info->get_cnt++;
		info->char_row++;
		print_move(info, 0);
	}
	else if (info->visited[(info->char_row) + 1][info->char_col] == 'E' \
	&& info->get_cnt == info->item_cnt)
		print_move(info, 1);
	else if (info->visited[(info->char_row) + 1][info->char_col] != '1' \
	&& info->visited[(info->char_row) + 1][info->char_col] != 'E')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[(info->char_row) + 1][info->char_col] = '0';
		info->visited[(info->char_row) + 1][info->char_col] = 'P';
		info->char_row++;
		print_move(info, 0);
	}
	my_mlx_print(info->visited, info->my_mlx);
}

void	move_a(t_info *info)
{
	if (info->visited[(info->char_row)][(info->char_col) - 1] == 'C')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[info->char_row][(info->char_col) - 1] = '0';
		info->visited[info->char_row][(info->char_col) - 1] = 'P';
		info->get_cnt++;
		info->char_col--;
		print_move(info, 0);
	}
	else if (info->visited[info->char_row][(info->char_col) - 1] == 'E' \
	&& info->get_cnt == info->item_cnt)
		print_move(info, 1);
	else if (info->visited[info->char_row][(info->char_col) - 1] != '1' \
	&& info->visited[info->char_row][(info->char_col) - 1] != 'E')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[info->char_row][(info->char_col) - 1] = '0';
		info->visited[info->char_row][(info->char_col) - 1] = 'P';
		info->char_col--;
		print_move(info, 0);
	}
	my_mlx_print(info->visited, info->my_mlx);
}

void	move_d(t_info *info)
{
	if (info->visited[(info->char_row)][(info->char_col) + 1] == 'C')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[info->char_row][(info->char_col) + 1] = '0';
		info->visited[info->char_row][(info->char_col) + 1] = 'P';
		info->get_cnt++;
		info->char_col++;
		print_move(info, 0);
	}
	else if (info->visited[info->char_row][(info->char_col) + 1] == 'E' \
	&& info->get_cnt == info->item_cnt)
		print_move(info, 1);
	else if (info->visited[info->char_row][(info->char_col) + 1] != '1' \
	&& info->visited[info->char_row][(info->char_col) + 1] != 'E')
	{
		info->visited[info->char_row][info->char_col] = '0';
		info->visited[info->char_row][(info->char_col) + 1] = '0';
		info->visited[info->char_row][(info->char_col) + 1] = 'P';
		info->char_col++;
		print_move(info, 0);
	}
	my_mlx_print(info->visited, info->my_mlx);
}
