/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:21:49 by seykim            #+#    #+#             */
/*   Updated: 2023/12/24 18:25:07 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "figure.h"
#include "../view/view.h"
#include "../vector/vector.h"

static int	hit_cylinder_side_sub(t_float_num *float_num, \
t_ray *ray, t_hit *rec, t_cylinder *cy);
static int	hit_cylinder_side_sub2(float root, t_ray *ray, \
t_hit *rec, t_cylinder *cy);

int	hit_cylinder_cap(t_cylinder *cy, t_ray *ray, t_hit *rec, float height)
{
	float		r;
	t_vector	circle_center;
	float		root;
	float		diameter;

	r = cy->num.delimeter / 2;
	circle_center = vec_add(cy->origin, vec_mul_num(cy->dir, height));
	root = vec_dot_product(vec_sub(circle_center, ray->origin), cy->dir) \
	/ vec_dot_product(ray->dir, cy->dir);
	diameter = vec_len(vec_sub(circle_center, ray_at(ray, root)));
	if (fabs(r) < fabs(diameter))
		return (0);
	if (root < rec->t_min || rec->t_max < root)
		return (0);
	rec->t = root;
	rec->coord = ray_at(ray, root);
	rec->t_max = rec->t;
	if (0 < height)
		rec->normal_vec = cy->dir;
	else
		rec->normal_vec = vec_mul_num(cy->dir, -1);
	set_face_normal(ray, rec);
	rec->albedo = cy->color;
	return (1);
}

int	hit_cylinder_side(t_cylinder *cy, t_ray *ray, t_hit *rec)
{
	t_vector	w;
	t_float_num	num_struct;
	int			res;

	num_struct.r = cy->num.delimeter / 2;
	w = vec_sub(ray->origin, cy->bot_origin);
	num_struct.a = vec_dot_product(ray->dir, ray->dir) - \
	powf(vec_dot_product(ray->dir, cy->dir), 2.0);
	num_struct.half_b = vec_dot_product(ray->dir, w) - \
	(vec_dot_product(ray->dir, cy->dir) * vec_dot_product(w, cy->dir));
	num_struct.c = vec_dot_product(w, w) - \
	powf(vec_dot_product(w, cy->dir), 2) - num_struct.r * num_struct.r;
	res = hit_cylinder_side_sub(&num_struct, ray, rec, cy);
	if (res == 0)
		return (0);
	return (1);
}

static int	hit_cylinder_side_sub(t_float_num *float_num, \
t_ray *ray, t_hit *rec, t_cylinder *cy)
{
	float		discriminant;
	float		sqrt_f;
	float		root;
	int			flag;

	discriminant = (float_num->half_b * float_num->half_b) \
	- (float_num->a * float_num->c);
	if (discriminant < FZERO)
		return (0);
	sqrt_f = sqrtf(discriminant);
	root = (-(float_num->half_b) - sqrt_f) / float_num->a;
	if (root < rec->t_min || rec->t_max < root)
	{
		root = (-(float_num->half_b) + sqrt_f) / float_num->a;
		if (root < rec->t_min || rec->t_max < root)
			return (0);
	}
	flag = hit_cylinder_side_sub2(root, ray, rec, cy);
	if (flag == 0)
		return (0);
	return (1);
}

static int	hit_cylinder_side_sub2(float root, t_ray *ray, \
t_hit *rec, t_cylinder *cy)
{
	float		hit_height;
	t_triple	temp_coord;

	temp_coord = ray_at(ray, root);
	hit_height = cy_boundary(cy, temp_coord);
	if (!hit_height)
		return (0);
	rec->t = root;
	rec->coord = temp_coord;
	rec->normal_vec = get_cylinder_normal(cy, rec->coord, hit_height);
	set_face_normal(ray, rec);
	rec->albedo = cy->color;
	return (1);
}
