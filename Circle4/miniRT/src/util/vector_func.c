/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:54:21 by seykim            #+#    #+#             */
/*   Updated: 2023/11/24 20:01:02 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vector	*vec_add(t_vector *obj, t_vector *a, t_vector *b)
{
	obj->x = a->x + b->x;
	obj->y = a->y + b->y;
	obj->z = a->z + b->z;
	return (obj);
}

t_vector	*vec_sub(t_vector *obj, t_vector *a, t_vector *b)
{
	obj->x = a->x - b->x;
	obj->y = a->y - b->y;
	obj->z = a->z - b->z;
	return (obj);
}

t_vector	*vec_mul(t_vector *obj, t_vector *a, t_vector *b)
{
	obj->x = a->x * b->x;
	obj->y = a->y * b->y;
	obj->z = a->z * b->z;
	return (obj);
}

t_vector	*vec_div(t_vector *obj, t_vector *a, t_vector *b)
{
	obj->x = a->x / b->x;
	obj->y = a->y / b->y;
	obj->z = a->z / b->z;
	return (obj);
}
