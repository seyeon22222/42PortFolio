/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeon <seyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:11:41 by seyeon            #+#    #+#             */
/*   Updated: 2023/11/28 17:14:39 by seyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_ray   *ray_set(t_ray *target, t_point *obj, t_vector *dir)
{
    target->obj = *obj;
    target->dir = *dir;
    return (target);
}

t_point *ray_point(t_point *target, t_ray *ray, float t)
{
    target->x = ray->obj.x + t * ray->dir.x;
    target->x = ray->obj.y + t * ray->dir.y;
    target->x = ray->obj.z + t * ray->dir.z;
    return (target);
}