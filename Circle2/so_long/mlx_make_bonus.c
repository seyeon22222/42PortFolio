/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_make_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:35:44 by seykim            #+#    #+#             */
/*   Updated: 2023/06/12 15:35:06 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**get_arr2_bonus(char **arr2, t_info *info, int i, char **argv)
{
	char	*arr;

	if (info->flag == 1)
	{
		free(arr2);
		return (0);
	}
	info->fd = open(argv[1], O_RDONLY);
	arr = get_next_line(info->fd);
	while (arr)
	{
		arr2[++i] = ft_strdup(arr);
		if (!arr2[i])
		{
			ft_free2_bonus(arr2, i);
			return (0);
		}
		free(arr);
		arr = get_next_line(info->fd);
	}
	arr2[++i] = 0;
	free(arr);
	close(info->fd);
	info->visited = visited_bonus(info, arr2);
	return (arr2);
}

t_info	*size_init_bonus(char **argv)
{
	t_info	*temp;
	char	*arr;

	temp = info_init_bonus();
	temp->fd = open(argv[1], O_RDONLY);
	if (temp->fd < 0)
		print_error_bonus(0);
	arr = get_next_line(temp->fd);
	temp->size_col = (int)ft_strlen(arr);
	while (arr)
	{
		if (temp->size_col != (int)ft_strlen(arr))
		{
			temp->flag = 1;
			free(arr);
			return (temp);
		}
		temp->size_row++;
		free(arr);
		arr = get_next_line(temp->fd);
	}
	temp->size_col = temp->size_col - 1;
	free(arr);
	close(temp->fd);
	return (temp);
}

t_info	*info_init_bonus(void)
{
	t_info	*temp;

	temp = (t_info *)malloc(sizeof(t_info));
	if (!temp)
		return (0);
	temp->char_cnt = 0;
	temp->char_col = 0;
	temp->char_row = 0;
	temp->exit_cnt = 0;
	temp->exit_col = 0;
	temp->exit_row = 0;
	temp->item_cnt = 0;
	temp->size_col = 0;
	temp->size_row = 0;
	temp->get_cnt = 0;
	temp->get_exit = 0;
	temp->flag = 0;
	temp->visited = 0;
	temp->my_mlx = 0;
	temp->fd = 0;
	temp->go_cnt = 0;
	temp->char_num = 0;
	return (temp);
}

t_mlx	*my_mlx_init_bonus(int size_col, int size_row)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (0);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, \
	size_col * 32, size_row * 32, "so_long");
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, "./wall.xpm", &mlx->w, &mlx->h);
	mlx->img1 = mlx_xpm_file_to_image(mlx->mlx, "./mine.xpm", &mlx->w, &mlx->h);
	mlx->img2 = mlx_xpm_file_to_image(mlx->mlx, "./tile.xpm", &mlx->w, &mlx->h);
	mlx->img3 = mlx_xpm_file_to_image(mlx->mlx, "./item.xpm", &mlx->w, &mlx->h);
	mlx->img4 = mlx_xpm_file_to_image(mlx->mlx, "./1.xpm", &mlx->w, &mlx->h);
	mlx->img5 = mlx_xpm_file_to_image(mlx->mlx, "./no.xpm", &mlx->w, &mlx->h);
	mlx->img6 = mlx_xpm_file_to_image(mlx->mlx, "./2.xpm", &mlx->w, &mlx->h);
	mlx->img7 = mlx_xpm_file_to_image(mlx->mlx, "./ok.xpm", &mlx->w, &mlx->h);
	return (mlx);
}

void	my_mlx_print_bonus(char **arr2, t_info *info, int i, int i2)
{
	char	*str;

	while (arr2[++i])
	{
		i2 = -1;
		while (arr2[i][++i2])
		{
			mlx_put_image_to_window(info->my_mlx->mlx, info->my_mlx->win, \
			info->my_mlx->img2, i2 * 32, i * 32);
			if (arr2[i][i2] == '1')
				mlx_put_image_to_window(info->my_mlx->mlx, info->my_mlx->win, \
				info->my_mlx->img, i2 * 32, i * 32);
			else if (arr2[i][i2] == 'A')
				mlx_put_image_to_window(info->my_mlx->mlx, info->my_mlx->win, \
				info->my_mlx->img1, i2 * 32, i * 32);
			else
				my_mlx_print_bonus2(arr2, info, i, i2);
		}
	}
	str = ft_itoa(info->go_cnt);
	mlx_string_put(info->my_mlx->mlx, info->my_mlx->win, \
	0, 0, 0x00FF0000, str);
	free(str);
}
