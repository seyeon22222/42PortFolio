/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:23:06 by seykim            #+#    #+#             */
/*   Updated: 2023/12/24 19:40:15 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initailize.h"
#include "../figure/figure.h"
#include "../vector/vector.h"
#include "../view/view.h"

static void	sphere_check2(char **split, int idx, t_sphere *sp_temp);
static void	sphere_check3(char *str, t_sphere *temp);
static void	sphere_check4(char *str, t_sphere *temp);

void	sphere_check(t_obj_list *temp, char *arr, int idx)
{
	char		**split;
	t_sphere	*sp_temp;

	split = ft_split(arr, 32);
	sp_temp = sphere(vec(0, 0, 0), vec(0, 0, 0), 0);
	sphere_check2(split, idx, sp_temp);
	free_split(split);
	obj_add(&temp, object(SPHERE, sp_temp, vec(0, 0, 0)));
}

static void	sphere_check2(char **split, int idx, t_sphere *sp_temp)
{
	while (split[idx])
	{
		if (idx == 1)
			sphere_check3(split[idx], sp_temp);
		else if (idx == 2)
			sp_temp->radius = ft_atof(split[idx]);
		else if (idx == 3)
			sphere_check4(split[idx], sp_temp);
		idx++;
	}
}

static void	sphere_check3(char *str, t_sphere *temp)
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
			temp->center.x = num;
		else if (idx == 1)
			temp->center.y = num;
		else if (idx == 2)
			temp->center.z = num;
		idx++;
	}
	free_split(split);
}

static void	sphere_check4(char *str, t_sphere *temp)
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
			print_error("Sphere R,G,B Range error");
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
