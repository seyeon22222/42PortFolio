/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:29:06 by seykim            #+#    #+#             */
/*   Updated: 2023/12/24 19:30:35 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../vector/vector.h"
#include "view.h"
#include "../figure/figure.h"

static t_bool	check_shadow(t_obj_list *obj_lst, \
t_ray light_ray, float light_len)
{
	t_hit	hit_rec;

	hit_rec.t_min = FZERO;
	hit_rec.t_max = light_len;
	if (hit(obj_lst, &light_ray, &hit_rec))
		return (TRUE);
	return (FALSE);
}

t_triple	point_light_get(t_light *light, t_obj_list *world, t_hit hit)
{
	t_vector	light_vec;
	t_ray		light_ray;
	float		diffuse_weight;

	hit.coord = vec_add(hit.coord, vec_mul_num(hit.normal_vec, 1e-3));
	light_vec = vec_sub(light->origin, hit.coord);
	light_ray = ray(hit.coord, light_vec);
	if (check_shadow(world, light_ray, vec_len(light_vec)))
		return (vec(0, 0, 0));
	diffuse_weight = fmaxf(vec_dot_product(hit.normal_vec, light_ray.dir), 0.0);
	return (vec_mul_num(vec(1, 1, 1), diffuse_weight));
}

t_triple	phong_lighting(t_info *info, t_obj_list *world, t_hit hit)
{
	t_triple	light_color;

	light_color = point_light_get(&(info->light), world, hit);
	light_color = vec_add(light_color, \
	vec_mul_num(vec_div_num(info->a_light.color, 255), info->a_light.ratio));
	if (light_color.x > 1.0)
		light_color.x = 1.0;
	if (light_color.y > 1.0)
		light_color.y = 1.0;
	if (light_color.z > 1.0)
		light_color.z = 1.0;
	return (vec_mul(light_color, hit.albedo));
}

t_light	*light_point(t_coord light_origin, t_triple color, float ratio)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		print_error("No space to Malloc light");
	light->origin = light_origin;
	light->color = color;
	light->ratio = ratio;
	return (light);
}
