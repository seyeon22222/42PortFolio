/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_func3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:56:15 by seykim            #+#    #+#             */
/*   Updated: 2023/11/24 20:09:16 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float	vec_len(t_vector *obj)
{
	return (sqrt(vec_len_sqr(obj)));
}

float	vec_len_sqr(t_vector *obj)
{
	float	num;

	num = pow(obj->x, 2.0) + pow(obj->y, 2.0) + pow(obj->z, 2.0);
	return (num);
}

t_vector	*vec_unit_vec(t_vector *obj, t_vector *a)
{
	return (vec_div_float(obj, vec_len(a), a));
}

t_vector	*vec_set_xyz(t_vector *obj, float x, float y, float z)
{
	obj->x = x;
	obj->y = y;
	obj->z = z;
	return (obj);
}
