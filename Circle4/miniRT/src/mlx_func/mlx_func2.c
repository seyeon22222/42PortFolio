/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:33:18 by seykim            #+#    #+#             */
/*   Updated: 2023/11/27 20:19:14 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_mlx	*my_mlx_init(int low, int col, t_list *info)
{
	t_mlx	*temp_mlx;

	temp_mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!temp_mlx)
		print_error("No space to malloc mlx");
	temp_mlx->mlx = mlx_init();
	temp_mlx->win = mlx_new_window(temp_mlx->mlx, low, col, "MiniRT");
	temp_mlx->info = info;
	return (temp_mlx);
}

int	move(t_data *data)
{
	if (data->left == 1 && data->x > 0)
		data->x -= 3;
	if (data->right == 1 && data->x + 100 < data->width)
		data->x += 3;
	if (data->up == 1 && data->y > 0)
		data->y -= 3;
	if (data->down == 1 && data->y + 100 < data->height)
		data->y += 3;
	if (data->up == 1 && data->z > 0)
		data->z -= 3;
	if (data->down == 1 && data->z + 100 < data->height)
		data->z += 3;
	return (0);
}

int	click_key(t_mlx *my_mlx)
{
	mlx_destroy_window(my_mlx->mlx, my_mlx->win);
	exit(0);
}

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }
// color = create_trgb(0, 255.999 * r, 255.999 * g, 255.999 * b);