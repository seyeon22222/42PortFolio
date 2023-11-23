/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:05 by seykim            #+#    #+#             */
/*   Updated: 2023/11/23 15:23:28 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	sphere_init(t_info *temp)
{
	temp->sphere.b_range = 0;
	temp->sphere.g_range = 0;
	temp->sphere.num = 0;
	temp->sphere.r_range = 0;
	temp->sphere.radius = 0;
	temp->sphere.x = 0;
	temp->sphere.y = 0;
	temp->sphere.z = 0;
}

void	light_init(t_info *temp)
{
	temp->light.b_range = 0;
	temp->light.g_range = 0;
	temp->light.num = 0;
	temp->light.r_range = 0;
	temp->light.ratio = 0;
	temp->light.x = 0;
	temp->light.y = 0;
	temp->light.z = 0;
}

void	plane_init(t_info *temp)
{
	temp->plane.b_range = 0;
	temp->plane.g_range = 0;
	temp->plane.num = 0;
	temp->plane.r_range = 0;
	temp->plane.vector_x = 0;
	temp->plane.vector_y = 0;
	temp->plane.vector_z = 0;
	temp->plane.x = 0;
	temp->plane.y = 0;
	temp->plane.z = 0;
}
