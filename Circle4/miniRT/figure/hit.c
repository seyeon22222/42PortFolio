/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:07:27 by seykim            #+#    #+#             */
/*   Updated: 2023/12/27 16:50:35 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "figure.h"

t_bool	hit(t_obj_list *world, t_ray *ray, t_hit *hit)
{
	t_bool	hit_anything;
	t_hit	temp_hit;

	temp_hit = *hit;
	hit_anything = FALSE;
	while (world)
	{
		if (hit_obj(world, ray, &temp_hit))
		{
			hit_anything = TRUE;
			temp_hit.t_max = temp_hit.t;
			*hit = temp_hit;
		}
		world = world->next;
	}
	return (hit_anything);
}

t_bool	hit_obj(t_obj_list *world, t_ray *ray, t_hit *hit)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (world->type == SPHERE)
		hit_result = hit_sphere(world->data, ray, hit);
	if (world->type == PLANE)
		hit_result = hit_plane(world->data, ray, hit);
	if (world->type == CYLINDER)
		hit_result = hit_cylinder(world->data, ray, hit);
	return (hit_result);
}
