/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:59:40 by seykim            #+#    #+#             */
/*   Updated: 2023/07/19 16:26:04 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	char	**arr2;
	int		flag;

	if (argc != 2)
		print_error_bonus(0);
	info = size_init_bonus(argv);
	arr2 = (char **)malloc(sizeof(char *) * (info->size_row + 1));
	if (!arr2)
		return (0);
	arr2 = get_arr2_bonus(arr2, info, -1, argv);
	flag = error_check_bonus(arr2, info);
	if (flag >= 1)
		print_error_bonus(flag);
	key_init_bonus(info, arr2);
	info->my_mlx = my_mlx_init_bonus(info->size_col, info->size_row);
	my_mlx_print_bonus(info->visited, info, -1, -1);
	mlx_hook(info->my_mlx->win, X_EVENT_KEY_PRESS, 0, &key_press_bonus, info);
	mlx_hook(info->my_mlx->win, X_EVENT_MOUSE_EXIT, 0, &click_key_bonus, info);
	mlx_loop(info->my_mlx);
	exit (0);
}

int	error_check_bonus(char **arr2, t_info *info)
{
	int	row;
	int	col;

	row = -1;
	if (info->flag == 1)
		return (1);
	while (++row < info->size_row && arr2[row])
	{
		col = -1;
		while (++col < info->size_col && arr2[row][col])
		{
			if (error_check2_bonus(row, col, arr2, info) == 1)
				return (2);
			else if (error_check3_bonus(row, col, arr2, info))
				return (2);
		}
	}
	if (info->char_cnt != 1 || info->exit_cnt != 1 || info->item_cnt < 1 \
	|| dfs_bonus(arr2, info->char_col, info->char_row, info))
		return (2);
	return (0);
}

int	dfs_bonus(char **arr2, int col, int row, t_info *info)
{
	if (info->visited[row][col] == '1' || info->visited[row][col] == 'A')
		return (1);
	info->visited[row][col] = '1';
	if (arr2[row][col] == 'C')
		info->get_cnt++;
	if (arr2[row][col] == 'E')
	{
		info->get_exit++;
		return (0);
	}
	if (arr2[row][col] != '1' && row >= 0 && \
	row < info->size_row && col >= 0 && col <= info->size_col)
	{
		dfs_bonus(arr2, col + 1, row, info);
		dfs_bonus(arr2, col, row + 1, info);
		dfs_bonus(arr2, col - 1, row, info);
		dfs_bonus(arr2, col, row - 1, info);
	}
	if ((!(info->item_cnt == info->get_cnt)) || info->get_exit != 1)
		return (1);
	int i = 0;
	while (info->visited[i])
	{
		printf("%s", info->visited[i]);
		i++;
	}
	printf("\n");
	return (0);
}

int	error_check2_bonus(int index_row, int index_col, char **arr2, t_info *info)
{
	if (index_row == 0)
	{
		if (arr2[index_row][index_col] != '1')
			return (1);
	}
	else if (index_row == info->size_row - 1)
	{
		if (arr2[index_row][index_col] != '1')
			return (1);
	}
	else if (index_col == 0)
	{
		if (arr2[index_row][index_col] != '1')
			return (1);
	}
	else if (index_col == info->size_col - 1)
	{
		if (arr2[index_row][index_col] != '1')
			return (1);
	}
	return (0);
}

int	error_check3_bonus(int row, int col, char **arr2, t_info *info)
{
	if (!(arr2[row][col] == '0' || arr2[row][col] == '1' || \
		arr2[row][col] == 'C' || arr2[row][col] == 'E' || \
		arr2[row][col] == 'P' || arr2[row][col] == 'A'))
		return (1);
	if (arr2[row][col] == 'C')
		info->item_cnt++;
	else if (arr2[row][col] == 'P')
	{
		info->char_col = col;
		info->char_row = row;
		info->char_cnt++;
	}
	else if (arr2[row][col] == 'E')
	{
		info->exit_cnt++;
		info->exit_col = col;
		info->exit_row = row;
	}
	return (0);
}
