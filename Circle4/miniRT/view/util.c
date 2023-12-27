/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:35:08 by seykim            #+#    #+#             */
/*   Updated: 2023/12/26 14:57:05 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "view.h"

void	print_error(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit(1);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	key_hook(int keycode, t_mlx *my_mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(my_mlx->mlx, my_mlx->win);
		mlx_destroy_image(my_mlx->mlx, my_mlx->data.img);
		exit(0);
	}
	return (0);
}

int	click_key(t_mlx *my_mlx)
{
	mlx_destroy_image(my_mlx->mlx, my_mlx->data.img);
	mlx_destroy_window(my_mlx->mlx, my_mlx->win);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
