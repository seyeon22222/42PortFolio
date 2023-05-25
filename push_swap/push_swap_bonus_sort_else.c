/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_sort_else.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:26:37 by seykim            #+#    #+#             */
/*   Updated: 2023/05/19 17:37:35 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	send_clock_b(int l_size, t_list **push_swap, \
t_list **push_swap2, int flag)
{
	double	chunck;
	double	num;

	chunck = (0.000000053 * (l_size * l_size)) + (0.03 * l_size) + 14.5;
	num = 0;
	while (*push_swap != NULL)
	{
		if ((*push_swap)->content <= num)
			pb_b(push_swap, push_swap2, flag);
		else if (num < (*push_swap)->content \
		&& (*push_swap)->content <= num + chunck)
		{
			pb_b(push_swap, push_swap2, flag);
			rb_b(push_swap2, flag);
		}
		else
		{
			ra_b(push_swap, flag);
			continue ;
		}
		num++;
	}
}

void	send_sort_b(t_list **push_swap, t_list **push_swap2, int max, int flag)
{
	int		big;
	t_list	*temp;

	while (--max >= 0)
	{
		temp = *push_swap2;
		big = 0;
		big = max_position(push_swap2, max);
		*push_swap2 = temp;
		if (flag == 1)
			send_sort3_b(push_swap, push_swap2, big, max);
		else
			send_sort2_b(push_swap, push_swap2, big, max);
	}
}

int	max_position(t_list **push_swap2, int max)
{
	int	cnt;
	int	big;

	cnt = 0;
	big = 0;
	while (*push_swap2 != NULL)
	{
		if (max == (*push_swap2)->content)
		{
			if (cnt >= max / 2)
			{
				big = 1;
				break ;
			}
		}
		*push_swap2 = (*push_swap2)->next;
		cnt++;
	}
	return (big);
}

void	send_sort2_b(t_list **push_swap, t_list **push_swap2, int big, int max)
{
	if (big == 0)
		while ((*push_swap2)->content != max)
			rb_b(push_swap2, 0);
	else if (big == 1)
		while ((*push_swap2)->content != max)
			rrb_b(push_swap2, 0);
	pa_b(push_swap, push_swap2, 0);
}

void	send_sort3_b(t_list **push_swap, t_list **push_swap2, int big, int max)
{
	if (big == 0)
		while ((*push_swap2)->content != max)
			rb_b(push_swap2, 1);
	else if (big == 1)
		while ((*push_swap2)->content != max)
			rrb_b(push_swap2, 1);
	pa_b(push_swap, push_swap2, 1);
}
