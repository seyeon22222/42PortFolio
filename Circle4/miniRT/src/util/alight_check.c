/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alight_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:59:46 by seykim            #+#    #+#             */
/*   Updated: 2023/11/27 19:38:41 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	alight_check2(char **split, int idx, t_alight *alight_temp, int *num);
static void	alight_check3(char *str, int *num, t_alight *temp);

void	alight_check(t_list *temp, char *arr, int idx)
{
	char		**split;
	t_alight	*alight_temp;
	int			num;

	num = 0;
	alight_temp = (t_alight *)malloc(sizeof(t_alight));
	if (!alight_temp)
		print_error("No space to malloc alight");
	alight_init(alight_temp);
	alight_temp->num++;
	if (alight_temp->num > 1)
		print_error("Alight Num error");
	split = ft_split(arr, 32);
	alight_check2(split, idx, alight_temp, &num);
	free_split(split);
	if (!temp->content)
	{
		free(temp);
		temp = ft_lstnew(alight_temp, alight);
	}
	else
		ft_lstadd_back(&temp, ft_lstnew(alight_temp, alight));
}

static void	alight_check2(char **split, \
int idx, t_alight *alight_temp, int *num)
{
	while (split[idx])
	{
		if (idx == 1)
		{
			alight_temp->ratio = ft_atof(split[idx]);
			if (!(alight_temp->ratio >= 0.0 && alight_temp->ratio <= 1.0))
				print_error("Ratio error");
		}
		else if (idx == 2)
			alight_check3(split[idx], num, alight_temp);
		idx++;
	}
}

static void	alight_check3(char *str, int *num, t_alight *temp)
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
				temp->r_range = *num;
			else if (idx == 1)
				temp->b_range = *num;
			else if (idx == 2)
				temp->g_range = *num;
		}
		idx++;
	}
	free_split(split);
}
