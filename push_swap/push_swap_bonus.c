/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:28:02 by seykim            #+#    #+#             */
/*   Updated: 2023/05/22 16:36:28 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_list	*push_swap;
	t_list	*push_swap2;
	t_list	*temp;
	int		l_size;
	int		*arr;

	if (argc < 2)
		return (-1);
	list_init_b(&temp, &push_swap, &push_swap2);
	l_size = list_insert_b(argv, &temp, &push_swap, 0);
	arr = ft_array_b(push_swap, l_size, 0, -1);
	temp = push_swap;
	error_check_bonus(l_size, &push_swap, arr);
	push_swap = temp;
	push_swap = order_check(&push_swap, &push_swap2, 1);
	if (sorted_b(push_swap, arr) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(arr);
	exit(0);
}

t_list	*order_check(t_list **push_swap, t_list **push_swap2, int flag)
{
	char	*order;

	order = get_next_line(0);
	while (order)
	{
		order1(push_swap, push_swap2, order, flag);
		free(order);
		order = NULL;
		order = get_next_line(0);
	}
	return (*push_swap);
}

void	order1(t_list **push_swap, t_list **push_swap2, char *order, int flag)
{
	if (order[0] == 's' && order[1] == 'a' && order[2] == '\n')
		sa_b(push_swap, flag);
	else if (order[0] == 's' && order[1] == 'b' && order[2] == '\n')
		sb_b(push_swap2, flag);
	else if (order[0] == 's' && order[1] == 's' && order[2] == '\n')
		ss_b(push_swap, push_swap2, flag);
	else if (order[0] == 'p' && order[1] == 'a' && order[2] == '\n')
		pa_b(push_swap, push_swap2, flag);
	else if (order[0] == 'p' && order[1] == 'b' && order[2] == '\n')
		pb_b(push_swap, push_swap2, flag);
	else if (order[0] == 'r' && order[1] == 'a' && order[2] == '\n')
		ra_b(push_swap, flag);
	else if (order[0] == 'r' && order[1] == 'b' && order[2] == '\n')
		rb_b(push_swap2, flag);
	else if (order[0] == 'r' && order[1] == 'r' && order[2] == '\n')
		rr_b(push_swap, push_swap2, flag);
	else if (order2(push_swap, push_swap2, order, flag))
		error_b();
}

int	order2(t_list **push_swap, t_list **push_swap2, char *order, int flag)
{
	if (order[0] == 'r' && order[1] == 'r' \
	&& order[2] == 'a' && order[3] == '\n')
		rra_b(push_swap, flag);
	else if (order[0] == 'r' && order[1] == 'r' \
	&& order[2] == 'b' && order[3] == '\n')
		rrb_b(push_swap2, flag);
	else if (order[0] == 'r' && order[1] == 'r' \
	&& order[2] == 'r' && order[3] == '\n')
		rrr_b(push_swap, push_swap2, flag);
	else
		return (1);
	return (0);
}

void	error_check_bonus(int l_size, t_list **push_swap, int *arr)
{
	list_indexing_b(l_size, push_swap, arr, 0);
	if (l_size < 2)
		exit(0);
}
