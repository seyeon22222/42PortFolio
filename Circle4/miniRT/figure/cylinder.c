/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:27:30 by seykim            #+#    #+#             */
/*   Updated: 2023/12/27 15:39:21 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "figure.h"
#include "../view/view.h"
#include "../vector/vector.h"

void	*cylinder(t_coord origin, t_triple color,
t_vector dir, t_cylinder_float num)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		print_error("No space to malloc cylinder");
	cylinder->origin = origin;
	cylinder->color = color;
	cylinder->dir = dir;
	cylinder->num.delimeter = num.delimeter;
	cylinder->num.height = num.height;
	return (cylinder);
}

t_cylinder_float	cylinder_float(float del, float height)
{
	t_cylinder_float	num;

	num.delimeter = del;
	num.height = height;
	return (num);
}

float	cy_boundary(t_cylinder *cy, t_vector at_point)
{
	float	hit_height;
	float	max_height;

	hit_height = vec_dot_product(vec_sub(at_point, cy->bot_origin), cy->dir);
	max_height = cy->num.height;
	if (fabs(hit_height) > max_height || hit_height < 0)
		return (0);
	return (hit_height);
}

t_vector	get_cylinder_normal(t_cylinder *cy,
t_vector at_point, float hit_height)
{
	t_triple	hit_center;
	t_vector	normal;

	hit_center = vec_add(cy->bot_origin, vec_mul_num(cy->dir, hit_height));
	normal = vec_sub(at_point, hit_center);
	return (vec_unit(normal));
}

t_bool	hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit *rec)
{
	int	result;

	result = 0;
	result += hit_cylinder_cap(cy, ray, rec, cy->num.height / 2);
	result += hit_cylinder_cap(cy, ray, rec, -(cy->num.height / 2));
	result += hit_cylinder_side(cy, ray, rec);
	return (result);
}
