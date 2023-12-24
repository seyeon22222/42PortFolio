/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alight_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:59:46 by seykim            #+#    #+#             */
/*   Updated: 2023/12/24 19:39:37 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initailize.h"
#include "../figure/figure.h"
#include "../vector/vector.h"
#include "../view/view.h"

static void	alight_check2(char **split, int idx, t_info *temp, int *num);
static void	alight_check3(char *str, int *num, t_info *temp);

void	alight_check(t_info *temp, char *arr, int idx)
{
	char		**split;
	int			num;

	num = 0;
	temp->a_light_num++;
	if (temp->a_light_num > 1)
		print_error("Alight Num error");
	split = ft_split(arr, 32);
	alight_check2(split, idx, temp, &num);
	free_split(split);
}

static void	alight_check2(char **split, int idx, t_info *temp, int *num)
{
	while (split[idx])
	{
		if (idx == 1)
		{
			temp->a_light.ratio = ft_atof(split[idx]);
			if (!(temp->a_light.ratio >= 0.0 && temp->a_light.ratio <= 1.0))
				print_error("Ratio error");
		}
		else if (idx == 2)
			alight_check3(split[idx], num, temp);
		idx++;
	}
}

static void	alight_check3(char *str, int *num, t_info *temp)
{
	char	**split;
	int		idx;

	split = ft_split(str, ',');
	idx = 0;
	while (split[idx])
	{
		*num = ft_atoi(split[idx]);
		if (*num < 0 || *num > 255)
			print_error("R,G,B range error");
		else
		{
			if (idx == 0)
				temp->a_light.color.x = *num;
			else if (idx == 1)
				temp->a_light.color.y = *num;
			else if (idx == 2)
				temp->a_light.color.z = *num;
		}
		idx++;
	}
	free_split(split);
}
