/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:23:06 by seykim            #+#    #+#             */
/*   Updated: 2023/11/27 19:44:03 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	light_check2(char **split, int idx, t_light *li_temp);
static void	light_check3(char *str, t_light *temp);
static void	light_check4(char *str, t_light *temp);

void	light_check(t_list *temp, char *arr, int idx)
{
	char	**split;
	t_light	*li_temp;

	li_temp = (t_light *)malloc(sizeof(t_light));
	if (!li_temp)
		print_error("No space to malloc light");
	light_init(li_temp);
	li_temp->num++;
	if (li_temp->num > 1)
		print_error("Light Num Error");
	split = ft_split(arr, 32);
	light_check2(split, idx, li_temp);
	free_split(split);
	if (!temp->content)
	{
		ft_lstdelone(temp, free);
		temp = ft_lstnew(li_temp, light);
	}
	else
		ft_lstadd_back(&temp, ft_lstnew(li_temp, light));
}

static void	light_check2(char **split, int idx, t_light *li_temp)
{
	float	num;

	num = 0;
	while (split[idx])
	{
		if (idx == 1)
			light_check3(split[idx], li_temp);
		else if (idx == 2)
		{
			num = ft_atof(split[idx]);
			if (num > 1 || num < 0)
				print_error("Light Ratio error");
			else
				li_temp->ratio = num;
		}
		else if (idx == 3)
			light_check4(split[idx], li_temp);
		idx++;
	}
}

static void	light_check3(char *str, t_light *temp)
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

static void	light_check4(char *str, t_light *temp)
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
			print_error("light R,G,B Range error");
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
