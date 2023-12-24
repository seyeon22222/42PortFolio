/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:38:21 by inhkim            #+#    #+#             */
/*   Updated: 2023/12/24 19:47:16 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include "../minirt.h"
# include "../mlx/mlx.h"
# include <stdio.h>

t_camera	init_camera(t_camera camera);
t_ray		ray(t_coord origin, t_vector vec);
t_vector	ray_at(t_ray *ray, float t);
t_ray		ray_primary(t_camera *cam, float u, float v);
t_vector	ray_color(t_ray *ray, t_obj_list *world, t_info *info);
void		raytracing(t_camera *cam, t_obj_list *world, \
t_mlx *mlx, t_info *info);
t_light		*light_point(t_coord light_origin, t_triple color, float ratio);
t_triple	point_light_get(t_light *light, t_obj_list *world, t_hit hit);
t_triple	phong_lighting(t_info *info, t_obj_list *world, t_hit hit);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
void		print_error(char *str);
int			key_hook(int keycode, t_mlx *my_mlx);

#endif