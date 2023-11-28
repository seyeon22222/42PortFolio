/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeon <seyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:56:58 by seykim            #+#    #+#             */
/*   Updated: 2023/11/28 17:17:32 by seyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define X_EVENT_KEY_PRESS		3
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_EXIT		17
# define KEY_ESC				53
# define KEY_UP					126
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_DOWN				125

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		x;
	int		y;
	int		z;
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

typedef t_vector t_point;
typedef t_vector t_color;

typedef struct s_ray
{
	t_point		obj;
	t_vector	dir;
}	t_ray;

typedef struct s_alight
{
	int			num;
	float		ratio;
	int			r_range;
	int			g_range;
	int			b_range;
	t_data		alight_data;
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
	int			num;
	float		ratio;
	int			r_range;
	int			g_range;
	int			b_range;
	float		x;
	float		y;
	float		z;
	t_data		light_data;
}	t_light;

typedef struct s_sphere
{
	float		x;
	float		y;
	float		z;
	float		radius;
	int			r_range;
	int			g_range;
	int			b_range;
	t_data		sphere_data;
}	t_sphere;

typedef struct s_plane
{
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
	t_list	*info;
}	t_mlx;

t_list		*file_init(char **argv);
void		alight_init(t_alight *temp);
void		camera_init(t_camera *temp);
void		cylinder_init(t_cylinder *temp);
void		sphere_init(t_sphere *temp);
void		light_init(t_light *temp);
void		plane_init(t_plane *temp);
void		cylinder_init(t_cylinder *temp);
void		alight_check(t_list *temp, char *arr, int idx);
void		camera_check(t_list *temp, char *arr, int idx);
void		cylinder_check(t_list *temp, char *arr, int idx);
void		check_arr(char *arr, t_list *temp);
void		arg_error(int argc, char **argv);
void		print_error(char *str);
void		free_split(char **res);
float		ft_atof(char *str);
void		light_check(t_list *temp, char *arr, int idx);
void		plane_check(t_list *temp, char *arr, int idx);
void		sphere_check(t_list *temp, char *arr, int idx);

//vector
t_vector	*vec_add(t_vector *obj, t_vector *a, t_vector *b);
t_vector	*vec_sub(t_vector *obj, t_vector *a, t_vector *b);
t_vector	*vec_mul(t_vector *obj, t_vector *a, t_vector *b);
t_vector	*vec_div(t_vector *obj, t_vector *a, t_vector *b);
t_vector	*vec_mul_float(t_vector *obj, float num, t_vector *a);
t_vector	*vec_div_float(t_vector *obj, float num, t_vector *a);
float		vec_dot(t_vector *a, t_vector *b);
t_vector	*vec_cross(t_vector *obj, t_vector *a, t_vector *b);
float		vec_len(t_vector *obj);
float		vec_len_sqr(t_vector *obj);
t_vector	*vec_unit_vec(t_vector *obj, t_vector *a);
t_vector	*vec_set_xyz(t_vector *obj, float x, float y, float z);

//mlx
t_mlx		*my_mlx_init(int low, int col, t_list *info);
int			key_press(int keycode, t_mlx *my_mlx);
int			camera_key_press(int keycode, t_camera *ca);
int			light_key_press(int keycode, t_light *li);
int			plane_key_press(int keycode, t_plane *pl);
int			cylinder_key_press(int keycode, t_cylinder *cy);
int			key_release(int keycode, t_mlx *my_mlx);
int			camera_key_release(int keycode, t_camera *ca);
int			light_key_release(int keycode, t_light *li);
int			plane_key_release(int keycode, t_plane *pl);
int			cylinder_key_release(int keycode, t_cylinder *cy);
int			click_key(t_mlx *my_mlx);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

//ray
t_ray		*ray_set(t_ray *target, t_point *obj, t_vector *dir);
t_point		*ray_point(t_point *target, t_ray *ray, float t);
#endif