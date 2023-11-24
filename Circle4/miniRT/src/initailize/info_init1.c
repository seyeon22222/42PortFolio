/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:07 by seykim            #+#    #+#             */
/*   Updated: 2023/11/24 19:52:31 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	alight_init(t_info *temp)
{
	temp->alight.b_range = 0;
	temp->alight.g_range = 0;
	temp->alight.num = 0;
	temp->alight.r_range = 0;
	temp->alight.ratio = 0;
}

void	camera_init(t_info *temp)
{
	temp->camera.fov = 0;
	temp->camera.num = 0;
	temp->camera.x = 0;
	temp->camera.y = 0;
	temp->camera.z = 0;
}

void	cylinder_init(t_info *temp)
{
	temp->cylinder.b_range = 0;
	temp->cylinder.delimeter = 0;
	temp->cylinder.g_range = 0;
	temp->cylinder.height = 0;
	temp->cylinder.num = 0;
	temp->cylinder.r_range = 0;
	temp->cylinder.x = 0;
	temp->cylinder.y = 0;
	temp->cylinder.z = 0;
}
