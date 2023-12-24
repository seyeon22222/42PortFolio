/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:23:06 by seykim            #+#    #+#             */
/*   Updated: 2023/12/24 19:39:57 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initailize.h"
#include "../figure/figure.h"
#include "../vector/vector.h"
#include "../view/view.h"

static void	cylinder_check2(char **split, int idx, t_cylinder *cy_temp);
static void	cylinder_check3(char *str, t_cylinder *temp);
static void	cylinder_check4(char *str, t_cylinder *temp);
static void	cylinder_check5(char *str, t_cylinder *temp);

void	cylinder_check(t_obj_list *temp, char *arr, int idx)
{
	char		**split;
	t_cylinder	*cy_temp;

	cy_temp = cylinder(vec(0, 0, 0), vec(0, 0, 0), \
	vec(0, 0, 0), cylinder_float(0, 0));
	split = ft_split(arr, 32);
	cylinder_check2(split, idx, cy_temp);
	free_split(split);
	cy_temp->dir = vec_unit(cy_temp->dir);
	cy_temp->bot_origin = vec_sub(cy_temp->origin, \
	vec_mul_num(cy_temp->dir, cy_temp->num.height / 2.0));
	obj_add(&temp, object(CYLINDER, cy_temp, vec(0, 0, 0)));
}

static void	cylinder_check2(char **split, int idx, t_cylinder *cy_temp)
{
	while (split[idx])
	{
		if (idx == 1)
			cylinder_check3(split[idx], cy_temp);
		else if (idx == 2)
			cylinder_check4(split[idx], cy_temp);
		else if (idx == 3)
			cy_temp->num.delimeter = ft_atof(split[idx]);
		else if (idx == 4)
			cy_temp->num.height = ft_atof(split[idx]);
		else if (idx == 5)
			cylinder_check5(split[idx], cy_temp);
		idx++;
	}
}

static void	cylinder_check3(char *str, t_cylinder *temp)
{
	char	**split;
	int		idx;
	float	num;

	split = ft_split(str, ',');
	idx = 0;
	while (split[idx])
	{
		num = ft_atof(split[idx]);
		if (idx == 0)
			temp->origin.x = num;
		else if (idx == 1)
			temp->origin.y = num;
		else if (idx == 2)
			temp->origin.z = num;
		idx++;
	}
	free_split(split);
}

static void	cylinder_check4(char *str, t_cylinder *temp)
{
	char	**split;
	int		idx;
	float	num;

	split = ft_split(str, ',');
	idx = 0;
	while (split[idx])
	{
		num = ft_atof(split[idx]);
		if (num > 1 || num < -1)
			print_error("Cylinder Vector Range error");
		else
		{
			if (idx == 0)
				temp->dir.x = num;
			else if (idx == 1)
				temp->dir.y = num;
			else if (idx == 2)
				temp->dir.z = num;
		}
		idx++;
	}
	free_split(split);
}

static void	cylinder_check5(char *str, t_cylinder *temp)
{
	char	**split;
	int		idx;
	float	num;

	split = ft_split(str, ',');
	idx = 0;
	while (split[idx])
	{
		num = ft_atoi(split[idx]);
		if (num > 255 || num < 0)
			print_error("Cylinder R,G,B Range error");
		else
		{
			if (idx == 0)
				temp->color.x = num;
			else if (idx == 1)
				temp->color.y = num;
			else if (idx == 2)
				temp->color.z = num;
		}
		idx++;
	}
	free_split(split);
}
