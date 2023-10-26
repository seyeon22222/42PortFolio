/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:56:58 by seykim            #+#    #+#             */
/*   Updated: 2023/10/11 15:59:17 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_alight
{
	int		num;
	float	ratio;
	int		r_range;
	int		g_range;
	int		b_range;
}	t_alight;

typedef struct s_camera
{
	int		num;
	float	x;
	float	y;
	float	z;
	int		fov;
	float	vector_x;
	float	vector_y;
	float	vector_z;
}	t_camera;

typedef struct s_light
{
	int		num;
	float	ratio;
	int		r_range;
	int		g_range;
	int		b_range;
	float	x;
	float	y;
	float	z;
}	t_light;

typedef struct s_sphere
{
	int		num;
	float	x;
	float	y;
	float	z;
	float	radius;
	int		r_range;
	int		g_range;
	int		b_range;
}	t_sphere;

typedef struct s_plat
{
	int		num;
	float	x;
	float	y;
	float	z;
	float	vector_x;
	float	vector_y;
	float	vector_z;
	int		r_range;
	int		g_range;
	int		b_range;
}	t_plat;

typedef struct s_rectangle
{
	int		num;
	float	x;
	float	y;
	float	z;
	float	vector_x;
	float	vector_y;
	float	vector_z;
	float	var;
	int		r_range;
	int		g_range;
	int		b_range;
}	t_rectangle;

typedef struct s_columnar
{
	int		num;
	float	x;
	float	y;
	float	z;
	float	vector_x;
	float	vector_y;
	float	vector_z;
	float	delimeter;
	float	height;
	int		r_range;
	int		g_range;
	int		b_range;
}	t_columnar;

typedef struct s_triangle
{
	int		num;
	float	x_1;
	float	y_1;
	float	z_1;
	float	x_2;
	float	y_2;
	float	z_2;
	float	x_3;
	float	y_3;
	float	z_3;
	int		r_range;
	int		g_range;
	int		b_range;
}	t_triangle;

typedef struct s_info
{
	t_alight	*alight;
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;
	t_plat		*plat;
	t_rectangle	*rectangle;
	t_columnar	*columnar;
	t_triangle	*triangle;
}	t_info;

#endif