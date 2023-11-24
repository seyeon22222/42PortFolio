/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:56:58 by seykim            #+#    #+#             */
/*   Updated: 2023/11/24 20:53:01 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "get_next_line.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define X_EVENT_KEY_PRESS			3
# define X_EVENT_MOUSE_EXIT			17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		x;
	int		y;
	int		up;
	int		down;
	int		left;
	int		right;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_alight
{
	int		num;
	float	ratio;
	int		r_range;
	int		g_range;
	int		b_range;
	t_data	alight_data;
}	t_alight;

typedef struct s_camera
{
	int			num;
	float		x;
	float		y;
	float		z;
	int			fov;
	t_data		camera_data;
	t_vector	cam_v;
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
	t_data	light_data;
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
	t_data	sphere_data;
}	t_sphere;

typedef struct s_plane
{
	int			num;
	float		x;
	float		y;
	float		z;
	int			r_range;
	int			g_range;
	int			b_range;
	t_data		plane_data;
	t_vector	pl_vec;
}	t_plane;

typedef struct s_cylinder
{
	int			num;
	float		x;
	float		y;
	float		z;
	float		delimeter;
	float		height;
	int			r_range;
	int			g_range;
	int			b_range;
	t_data		cylinder_data;
	t_vector	cy_vec;
}	t_cylinder;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	*data;
}	t_mlx;

typedef struct s_info
{
	t_alight	alight;
	t_camera	camera;
	t_light		light;
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
	t_mlx		*my_mlx;
	// int			(*hit)(t_cylinder *);
	int			total_num;
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
void	camera_check(t_info **temp, char *arr, int idx);
void	light_check(t_info **temp, char *arr, int idx);
void	sphere_check(t_info **temp, char *arr, int idx);
void	plane_check(t_info **temp, char *arr, int idx);
void	cylinder_check(t_info **temp, char *arr, int idx);
t_mlx	*my_mlx_init(int low, int col, int num, t_info *info);
int		key_press(int keycode, t_info *info);
int		click_key(t_info *info);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif