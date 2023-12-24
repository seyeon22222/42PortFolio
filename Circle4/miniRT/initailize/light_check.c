/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:23:06 by seykim            #+#    #+#             */
/*   Updated: 2023/12/24 19:40:11 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initailize.h"
#include "../figure/figure.h"
#include "../vector/vector.h"
#include "../view/view.h"

static void	light_check2(char **split, int idx, t_info *li_temp);
static void	light_check3(char *str, t_info *temp);
static void	light_check4(char *str, t_info *temp);

void	light_check(t_info *temp, char *arr, int idx)
{
	char	**split;

	temp->light_num++;
	if (temp->light_num > 1)
		print_error("Light Num Error");
	split = ft_split(arr, 32);
	light_check2(split, idx, temp);
	free_split(split);
}

static void	light_check2(char **split, int idx, t_info *temp)
{
	float	num;

	num = 0;
	while (split[idx])
	{
		if (idx == 1)
			light_check3(split[idx], temp);
		else if (idx == 2)
		{
			num = ft_atof(split[idx]);
			if (num > 1 || num < 0)
				print_error("Light Ratio error");
			else
				temp->light.ratio = num;
		}
		else if (idx == 3)
			light_check4(split[idx], temp);
		idx++;
	}
}

static void	light_check3(char *str, t_info *temp)
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
			temp->light.origin.x = num;
		else if (idx == 1)
			temp->light.origin.y = num;
		else if (idx == 2)
			temp->light.origin.z = num;
		idx++;
	}
	free_split(split);
}

static void	light_check4(char *str, t_info *temp)
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
				temp->light.color.x = num;
			else if (idx == 1)
				temp->light.color.y = num;
			else if (idx == 2)
				temp->light.color.z = num;
		}
		idx++;
	}
	free_split(split);
}
