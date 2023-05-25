/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:40:19 by seykim            #+#    #+#             */
/*   Updated: 2023/05/23 14:52:13 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*push_swap;
	t_list	*push_swap2;
	t_list	*temp;
	int		l_size;
	int		*arr;

	if (argc < 2)
		return (-1);
	list_init(&temp, &push_swap, &push_swap2);
	l_size = list_insert(argv, &temp, &push_swap, 0);
	arr = ft_array(push_swap, l_size, 0, -1);
	temp = push_swap;
	error_check(l_size, &push_swap, &push_swap2, arr);
	free(arr);
	push_swap = temp;
	sorted_arr(l_size, &push_swap, &push_swap2, 0);
	exit(0);
}
