/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:48:24 by seykim            #+#    #+#             */
/*   Updated: 2023/05/22 20:07:35 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	bubble(int i, int l_size, int *arr)
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
				swap(&arr[i], &arr[j]);
		}
	}
	return (flag);
}

void	ft_free2(char **new)
{
	int	i;

	if (new == NULL)
		return ;
	i = 0;
	while (new[i])
	{
		free(new[i]);
		i++;
	}
	free(new);
}

void	error_check(int l_size, t_list **push_swap, \
t_list **push_swap2, int *arr)
{
	list_indexing(l_size, push_swap, arr, 0);
	if (l_size < 2 || (sorted(*push_swap, arr) == 0 && *push_swap2 == 0))
		exit(0);
}
