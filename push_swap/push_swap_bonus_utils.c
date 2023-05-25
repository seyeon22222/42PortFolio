/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:48:24 by seykim            #+#    #+#             */
/*   Updated: 2023/05/22 16:18:11 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_b(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	error_b(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

int	bubble_b(int i, int l_size, int *arr)
{
	int	flag;
	int	j;

	flag = 0;
	while (++i < l_size - 1)
	{
		j = i;
		while (++j < l_size)
		{
			if (arr[i] == arr[j])
			{
				flag = 1;
				break ;
			}
			if (arr[i] > arr[j])
				swap_b(&arr[i], &arr[j]);
		}
	}
	return (flag);
}

void	ft_free2_b(char **new)
{
	int	i;

	if (new == 0)
		return ;
	i = 0;
	while (new[i])
	{
		free(new[i]);
		i++;
	}
	free(new);
}
