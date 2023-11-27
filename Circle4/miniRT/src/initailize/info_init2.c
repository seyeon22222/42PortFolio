/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:05 by seykim            #+#    #+#             */
/*   Updated: 2023/11/27 18:20:14 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	sphere_init(t_sphere *temp)
{
	temp->b_range = 0;
	temp->g_range = 0;
	temp->r_range = 0;
	temp->radius = 0;
	temp->x = 0;
	temp->y = 0;
	temp->z = 0;
}

void	light_init(t_light *temp)
{
	temp->b_range = 0;
	temp->g_range = 0;
	temp->num = 0;
	temp->r_range = 0;
	temp->ratio = 0;
	temp->x = 0;
	temp->y = 0;
	temp->z = 0;
}

void	plane_init(t_plane *temp)
{
	temp->b_range = 0;
	temp->g_range = 0;
	temp->r_range = 0;
	temp->x = 0;
	temp->y = 0;
	temp->z = 0;
}
