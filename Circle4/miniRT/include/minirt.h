/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:56:58 by seykim            #+#    #+#             */
/*   Updated: 2023/11/23 20:52:43 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

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

typedef struct s_plane
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
}	t_plane;

typedef struct s_cylinder
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
}	t_cylinder;

typedef struct s_info
{
	t_alight	alight;
	t_camera	camera;
	t_light		light;
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
	// int			(*hit)(t_cylinder *);
}	t_info;

void	arg_error(int argc, char **argv);
void	check_arr(char *arr, t_info **temp);
void	alight_init(t_info *temp);
void	camera_init(t_info *temp);
void	cylinder_init(t_info *temp);
void	light_init(t_info *temp);
void	plane_init(t_info *temp);
void	sphere_init(t_info *temp);
void	print_error(char *str);
t_info	*info_init(void);
t_info	*file_init(char **argv);
float	ft_atof(char *str);
void	free_split(char **res);
void	alight_check(t_info **temp, char *arr, int idx);
void	alight_check2(char *str, int *num, t_info **temp);
void	camera_check(t_info **temp, char *arr, int idx);
void	camera_check2(char *str, t_info **temp);
void	camera_check3(char *str, t_info **temp);
#endif