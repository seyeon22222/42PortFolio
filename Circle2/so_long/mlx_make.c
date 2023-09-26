/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:35:44 by seykim            #+#    #+#             */
/*   Updated: 2023/09/18 14:34:02 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_arr2(char **arr2, t_info *info, int i, char **argv)
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
			ft_free2(arr2, i);
			return (0);
		}
		free(arr);
		arr = get_next_line(info->fd);
	}
	arr2[++i] = 0;
	free(arr);
	close(info->fd);
	info->visited = visited(info, arr2);
	return (arr2);
}

t_info	*size_init(char **argv)
{
	t_info	*temp;
	char	*arr;

	temp = info_init();
	temp->fd = open(argv[1], O_RDONLY);
	if (temp->fd < 0)
		print_error(0);
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

t_info	*info_init(void)
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
	return (temp);
}

t_mlx	*my_mlx_init(int size_col, int size_row)
{
	t_mlx	*new_mlx;

	new_mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!new_mlx)
		return (0);
	new_mlx->mlx = mlx_init();
	new_mlx->win = mlx_new_window(new_mlx->mlx, \
	size_col * 32, size_row * 32, "so_long");
	new_mlx->img = mlx_xpm_file_to_image(new_mlx->mlx, \
	"./wall.xpm", &new_mlx->img_width, &new_mlx->img_height);
	new_mlx->img2 = mlx_xpm_file_to_image(new_mlx->mlx, \
	"./tile.xpm", &new_mlx->img_width, &new_mlx->img_height);
	new_mlx->img3 = mlx_xpm_file_to_image(new_mlx->mlx, \
	"./item.xpm", &new_mlx->img_width, &new_mlx->img_height);
	new_mlx->img4 = mlx_xpm_file_to_image(new_mlx->mlx, \
	"./1.xpm", &new_mlx->img_width, &new_mlx->img_height);
	new_mlx->img5 = mlx_xpm_file_to_image(new_mlx->mlx, \
	"./ok.xpm", &new_mlx->img_width, &new_mlx->img_height);
	return (new_mlx);
}

void	my_mlx_print(char **arr2, t_mlx *my_mlx)
{
	int	i;
	int	index;

	i = -1;
	while (arr2[++i])
	{
		index = -1;
		while (arr2[i][++index])
		{
			mlx_put_image_to_window(my_mlx->mlx, my_mlx->win, \
			my_mlx->img2, index * 32, i * 32);
			if (arr2[i][index] == '1')
				mlx_put_image_to_window(my_mlx->mlx, my_mlx->win, \
				my_mlx->img, index * 32, i * 32);
			else if (arr2[i][index] == 'C')
				mlx_put_image_to_window(my_mlx->mlx, my_mlx->win, \
				my_mlx->img3, index * 32, i * 32);
			else if (arr2[i][index] == 'P')
				mlx_put_image_to_window(my_mlx->mlx, my_mlx->win, \
				my_mlx->img4, index * 32, i * 32);
			else if (arr2[i][index] == 'E')
				mlx_put_image_to_window(my_mlx->mlx, my_mlx->win, \
				my_mlx->img5, index * 32, i * 32);
		}
	}
}
