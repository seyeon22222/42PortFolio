/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:23:06 by seykim            #+#    #+#             */
/*   Updated: 2023/12/24 19:40:13 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initailize.h"
#include "../figure/figure.h"
#include "../vector/vector.h"
#include "../view/view.h"

static void	plane_check2(char **split, int idx, t_plane *pl_temp);
static void	plane_check3(char *str, t_plane *temp);
static void	plane_check4(char *str, t_plane *temp);
static void	plane_check5(char *str, t_plane *temp);

void	plane_check(t_obj_list *temp, char *arr, int idx)
{
	char	**split;
	t_plane	*pl_temp;

	pl_temp = plane(vec(0, 0, 0), vec(0, 0, 0), vec(0, 0, 0));
	split = ft_split(arr, 32);
	plane_check2(split, idx, pl_temp);
	free_split(split);
	obj_add(&temp, object(PLANE, pl_temp, vec(0, 0, 0)));
}

static void	plane_check2(char **split, int idx, t_plane *pl_temp)
{
	while (split[idx])
	{
		if (idx == 1)
			plane_check3(split[idx], pl_temp);
		else if (idx == 2)
			plane_check4(split[idx], pl_temp);
		else if (idx == 3)
			plane_check5(split[idx], pl_temp);
		idx++;
	}
}

static void	plane_check3(char *str, t_plane *temp)
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

static void	plane_check4(char *str, t_plane *temp)
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
			print_error("Plane Vector Range error");
		else
		{
			if (idx == 0)
				temp->pl_normal.x = num;
			else if (idx == 1)
				temp->pl_normal.y = num;
			else if (idx == 2)
				temp->pl_normal.z = num;
		}
		idx++;
	}
	free_split(split);
}

static void	plane_check5(char *str, t_plane *temp)
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
			print_error("Plane R,G,B Range error");
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
