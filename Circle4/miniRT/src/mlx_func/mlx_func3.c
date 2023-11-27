/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:19:26 by seykim            #+#    #+#             */
/*   Updated: 2023/11/27 20:21:40 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	key_release(int keycode, t_mlx *my_mlx)
{
	t_list	*temp;

	temp = my_mlx->info;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(my_mlx->mlx, my_mlx->win);
		exit(0);
	}
	while (my_mlx->info)
	{
		if (my_mlx->info->figure == camera)
			camera_key_release(keycode, (t_camera *)(my_mlx->info->content));
		else if (my_mlx->info->figure == light)
			light_key_release(keycode, (t_light *)(my_mlx->info->content));
		else if (my_mlx->info->figure == plane)
			plane_key_release(keycode, (t_plane *)(my_mlx->info->content));
		else if (my_mlx->info->figure == cylinder)
			cylinder_key_release(keycode, \
			(t_cylinder *)(my_mlx->info->content));
		my_mlx->info = my_mlx->info->next;
	}
	my_mlx->info = temp;
	return (0);
}

int	camera_key_release(int keycode, t_camera *ca)
{
	if (keycode == KEY_LEFT)
		ca->camera_data.left = 0;
	if (keycode == KEY_RIGHT)
		ca->camera_data.right = 0;
	if (keycode == KEY_UP)
		ca->camera_data.up = 0;
	if (keycode == KEY_DOWN)
		ca->camera_data.down = 0;
	return (0);
}

int	light_key_release(int keycode, t_light *li)
{
	if (keycode == KEY_LEFT)
		li->light_data.left = 0;
	if (keycode == KEY_RIGHT)
		li->light_data.right = 0;
	if (keycode == KEY_UP)
		li->light_data.up = 0;
	if (keycode == KEY_DOWN)
		li->light_data.down = 0;
	return (0);
}

int	plane_key_release(int keycode, t_plane *pl)
{
	if (keycode == KEY_LEFT)
		pl->plane_data.left = 0;
	if (keycode == KEY_RIGHT)
		pl->plane_data.right = 0;
	if (keycode == KEY_UP)
		pl->plane_data.up = 0;
	if (keycode == KEY_DOWN)
		pl->plane_data.down = 0;
	return (0);
}

int	cylinder_key_release(int keycode, t_cylinder *cy)
{
	if (keycode == KEY_LEFT)
		cy->cylinder_data.left = 0;
	if (keycode == KEY_RIGHT)
		cy->cylinder_data.right = 0;
	if (keycode == KEY_UP)
		cy->cylinder_data.up = 0;
	if (keycode == KEY_DOWN)
		cy->cylinder_data.down = 0;
	return (0);
}
