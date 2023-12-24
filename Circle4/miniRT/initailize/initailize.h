/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initailize.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:26:09 by seykim            #+#    #+#             */
/*   Updated: 2023/12/24 19:26:09 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITAILIZE_H
# define INITAILIZE_H

# include "../minirt.h"
# include "../libft/libft.h"

void	file_init(char **argv, t_obj_list *obj_list, t_info *info);
void	check_arr(char *arr, t_obj_list *temp, t_info *info);
void	alight_check(t_info *temp, char *arr, int idx);
void	camera_check(t_info *temp, char *arr, int idx);
void	cylinder_check(t_obj_list *temp, char *arr, int idx);
void	arg_error(int argc, char **argv);
void	free_split(char **res);
void	light_check(t_info *temp, char *arr, int idx);
void	plane_check(t_obj_list *temp, char *arr, int idx);
void	sphere_check(t_obj_list *temp, char *arr, int idx);
float	ft_atof(char *str);
#endif