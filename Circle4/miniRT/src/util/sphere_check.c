/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:23:06 by seykim            #+#    #+#             */
/*   Updated: 2023/11/27 19:46:34 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	sphere_check2(char **split, int idx, t_sphere *sp_temp);
static void	sphere_check3(char *str, t_sphere *temp);
static void	sphere_check4(char *str, t_sphere *temp);

void	sphere_check(t_list *temp, char *arr, int idx)
{
	char		**split;
	t_sphere	*sp_temp;

	split = ft_split(arr, 32);
	sp_temp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sp_temp)
		print_error("No space to malloc sphere");
	sphere_init(sp_temp);
	sphere_check2(split, idx, sp_temp);
	free_split(split);
	if (!temp->content)
	{
		ft_lstdelone(temp, free);
		temp = ft_lstnew(sp_temp, sphere);
	}
	else
		ft_lstadd_back(&temp, ft_lstnew(sp_temp, sphere));
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
			temp->x = num;
		else if (idx == 1)
			temp->y = num;
		else if (idx == 2)
			temp->z = num;
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
