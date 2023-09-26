/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_345.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:39:00 by seykim            #+#    #+#             */
/*   Updated: 2023/06/02 19:57:59 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_size(int l_size, t_list **push_swap, \
t_list **push_swap2, int flag)
{
	if (l_size == 2)
		sa(push_swap, flag);
	else if (l_size == 3)
		sort_3(push_swap, flag);
	else if (l_size == 4)
		sort_4(push_swap, push_swap2, flag);
	else
		sort_5(push_swap, push_swap2, 0, flag);
}

void	sort_3(t_list **push_swap, int flag)
{
	if ((*push_swap)->content == 2)
	{
		if ((*push_swap)->next->content == 0)
		{
			ra(push_swap, flag);
			return ;
		}
		sa(push_swap, flag);
		rra(push_swap, flag);
	}
	else if ((*push_swap)->content == 1)
	{
		if ((*push_swap)->next->content == 0)
			sa(push_swap, flag);
		else
			rra(push_swap, flag);
	}
	else if ((*push_swap)->next->content == 2)
	{
		sa(push_swap, flag);
		ra(push_swap, flag);
	}
	else
		return ;
}

void	sort_4(t_list **push_swap, t_list **push_swap2, int flag)
{
	t_list	*temp;
	int		cnt;

	temp = *push_swap;
	cnt = 0;
	while ((*push_swap)->content != 3)
	{
		cnt++;
		*push_swap = (*push_swap)->next;
	}
	*push_swap = temp;
	if (cnt == 1)
		ra(push_swap, flag);
	else if (cnt == 2)
	{
		rra(push_swap, flag);
		rra(push_swap, flag);
	}
	else if (cnt == 3)
		rra(push_swap, flag);
	pb(push_swap, push_swap2, flag);
	sort_3(push_swap, flag);
	pa(push_swap, push_swap2, flag);
	ra(push_swap, flag);
}

void	sort_5(t_list **push_swap, t_list **push_swap2, int cnt, int flag)
{
	t_list	*temp;

	temp = *push_swap;
	while ((*push_swap)->content != 4)
	{
		cnt++;
		*push_swap = (*push_swap)->next;
	}
	*push_swap = temp;
	if (cnt == 1)
		ra(push_swap, flag);
	else if (cnt == 2)
	{
		ra(push_swap, flag);
		ra(push_swap, flag);
	}
	else if (cnt == 3)
	{
		rra(push_swap, flag);
		rra(push_swap, flag);
	}
	else if (cnt == 4)
		rra(push_swap, flag);
	sort_5_sub(push_swap, push_swap2, flag);
}

void	sort_5_sub(t_list **push_swap, t_list **push_swap2, int flag)
{
	pb(push_swap, push_swap2, flag);
	sort_4(push_swap, push_swap2, flag);
	pa(push_swap, push_swap2, flag);
	ra(push_swap, flag);
}
