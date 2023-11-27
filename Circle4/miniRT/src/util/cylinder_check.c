/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:23:06 by seykim            #+#    #+#             */
/*   Updated: 2023/11/27 19:42:38 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	cylinder_check2(char **split, int idx, t_cylinder *cy_temp);
static void	cylinder_check3(char *str, t_cylinder *temp);
static void	cylinder_check4(char *str, t_cylinder *temp);
static void	cylinder_check5(char *str, t_cylinder *temp);

void	cylinder_check(t_list *temp, char *arr, int idx)
{
	char		**split;
	t_cylinder	*cy_temp;

	cy_temp = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cy_temp)
		print_error("No space to malloc cylinder");
	cylinder_init(cy_temp);
	split = ft_split(arr, 32);
	cylinder_check2(split, idx, cy_temp);
	free_split(split);
	if (!temp->content)
	{
		ft_lstdelone(temp, free);
		temp = ft_lstnew(cy_temp, cylinder);
	}
	else
		ft_lstadd_back(&temp, ft_lstnew(cy_temp, cylinder));
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
			cy_temp->delimeter = ft_atof(split[idx]);
		else if (idx == 4)
			cy_temp->height = ft_atof(split[idx]);
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
			temp->x = num;
		else if (idx == 1)
			temp->y = num;
		else if (idx == 2)
			temp->z = num;
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
				temp->cy_vec.x = num;
			else if (idx == 1)
				temp->cy_vec.y = num;
			else if (idx == 2)
				temp->cy_vec.z = num;
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
				temp->r_range = num;
			else if (idx == 1)
				temp->g_range = num;
			else if (idx == 2)
				temp->b_range = num;
		}
		idx++;
	}
	free_split(split);
}
