/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:41:43 by inhkim            #+#    #+#             */
/*   Updated: 2023/12/27 16:52:58 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"
#include "../vector/vector.h"
#include "../figure/figure.h"
#include "../view/view.h"
#include "../mlx/mlx.h"

t_ray	ray(t_coord origin, t_vector vec)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = vec_unit(vec);
	return (ray);
}

t_coord	ray_at(t_ray *ray, float t)
{
	return (vec_add(ray->origin, vec_mul_num(ray->dir, t)));
}

t_ray	ray_primary(t_camera *cam, float x, float y)
{
	t_vector	ray_vec;
	t_coord		destination;
	t_coord		d_horizon;
	t_coord		d_vertical;

	d_horizon = vec_mul_num(cam->horizon_vec, x);
	d_vertical = vec_mul_num(cam->vertical_vec, y);
	destination = vec_add(vec_add(cam->left_bottom, d_horizon), d_vertical);
	ray_vec = vec_sub(destination, cam->origin);
	return (ray(cam->origin, ray_vec));
}

t_vector	ray_color(t_ray *ray, t_obj_list *world, t_info *info)
{
	t_hit		hit_rec;

	hit_rec.t_min = FZERO;
	hit_rec.t_max = FINF;
	if (hit(world, ray, &hit_rec))
		return (phong_lighting(info, world, hit_rec));
	hit_rec.t = 0.5 * (ray->dir.y + 1.0);
	return (vec_mul_num(vec(1.0 - 0.5 * hit_rec.t, \
	1.0 - 0.3 * hit_rec.t, 1.0), 255));
}

void	raytracing(t_camera *cam, t_obj_list *world, t_mlx *mlx, t_info *info)
{
	int			x;
	int			y;
	t_ray		ray;
	t_triple	pixel_color;

	y = HEIGHT - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = ray_primary(cam, x / (float)(WIDTH - 1), \
			y / (float)(HEIGHT - 1));
			pixel_color = ray_color(&ray, world, info);
			my_mlx_pixel_put(&mlx->data, x, HEIGHT - 1 - y, \
			create_trgb(0, pixel_color.x, pixel_color.y, pixel_color.z));
			++x;
		}
		--y;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->data.img, 0, 0);
}
