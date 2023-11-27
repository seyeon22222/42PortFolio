/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:56:15 by seykim            #+#    #+#             */
/*   Updated: 2023/11/24 20:05:55 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vector	*vec_mul_float(t_vector *obj, float num, t_vector *a)
{
	obj->x = a->x * num;
	obj->y = a->y * num;
	obj->z = a->z * num;
	return (obj);
}

t_vector	*vec_div_float(t_vector *obj, float num, t_vector *a)
{
	return (vec_mul_float(obj, (1 / num), a));
}

// 내적
float	vec_dot(t_vector *a, t_vector *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

// 외적
t_vector	*vec_cross(t_vector *obj, t_vector *a, t_vector *b)
{
	obj->x = a->y * b->z - a->z * b->y;
	obj->y = a->z * b->x - a->x * b->z;
	obj->z = a->x * b->y - a->y * b->x;
	return (obj);
}
