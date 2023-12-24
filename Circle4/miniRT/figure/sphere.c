/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:10:44 by seykim            #+#    #+#             */
/*   Updated: 2023/12/24 19:17:44 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "figure.h"
#include "../view/view.h"
#include "../vector/vector.h"

static void	hit_sphere_sub(t_hit *hit, t_sphere *sp, t_ray *ray, float root);

void	*sphere(t_coord center, t_triple color, double radius)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		print_error("No space to malloc sphere");
	sphere->center = center;
	sphere->radius = radius;
	sphere->color = color;
	return (sphere);
}

void	set_face_normal(t_ray *r, t_hit *rec)
{
	rec->front_face = vec_dot_product(r->dir, rec->normal_vec) < 0;
	if (!rec->front_face)
		rec->normal_vec = vec_mul_num(rec->normal_vec, -1);
}

t_bool	hit_sphere(t_sphere *sp, t_ray *ray, t_hit *hit)
{
	t_vector	co;
	t_float_num	num_struct;
	float		discriminant;
	float		sqrt_d;
	float		root;

	co = vec_sub(ray->origin, sp->center);
	num_struct.a = vec_len_square(ray->dir);
	num_struct.half_b = vec_dot_product(co, ray->dir);
	num_struct.c = vec_len_square(co) - (sp->radius * sp->radius);
	discriminant = num_struct.half_b * num_struct.half_b \
	- num_struct.a * num_struct.c;
	if (discriminant < FZERO)
		return (FALSE);
	sqrt_d = sqrt(discriminant);
	root = (-num_struct.half_b - sqrt_d) / num_struct.a;
	if (root < hit->t_min || hit->t_max < root)
	{
		root = (-num_struct.half_b + sqrt_d) / num_struct.a;
		if (root < hit->t_min || hit->t_max < root)
			return (FALSE);
	}
	hit_sphere_sub(hit, sp, ray, root);
	return (TRUE);
}

static void	hit_sphere_sub(t_hit *hit, t_sphere *sp, t_ray *ray, float root)
{
	hit->t = root;
	hit->coord = ray_at(ray, root);
	hit->normal_vec = vec_div_num(vec_sub(hit->coord, sp->center), sp->radius);
	hit->albedo = sp->color;
	set_face_normal(ray, hit);
}
