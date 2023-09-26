/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_sort_345.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:39:00 by seykim            #+#    #+#             */
/*   Updated: 2023/05/19 17:37:45 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	small_size_b(int l_size, t_list **push_swap, \
t_list **push_swap2, int flag)
{
	if (l_size == 2)
		sa_b(push_swap, flag);
	else if (l_size == 3)
		sort_3_b(push_swap, flag);
	else if (l_size == 4)
		sort_4_b(push_swap, push_swap2, flag);
	else
		sort_5_b(push_swap, push_swap2, 0, flag);
}

void	sort_3_b(t_list **push_swap, int flag)
{
	if ((*push_swap)->content == 2)
	{
		if ((*push_swap)->next->content == 0)
		{
			ra_b(push_swap, flag);
			return ;
		}
		sa_b(push_swap, flag);
		rra_b(push_swap, flag);
	}
	else if ((*push_swap)->content == 1)
	{
		if ((*push_swap)->next->content == 0)
			sa_b(push_swap, flag);
		else
			rra_b(push_swap, flag);
	}
	else if ((*push_swap)->next->content == 2)
	{
		sa_b(push_swap, flag);
		ra_b(push_swap, flag);
	}
	else
		return ;
}

void	sort_4_b(t_list **push_swap, t_list **push_swap2, int flag)
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
		ra_b(push_swap, flag);
	else if (cnt == 2)
	{
		rra_b(push_swap, flag);
		rra_b(push_swap, flag);
	}
	else if (cnt == 3)
		rra_b(push_swap, flag);
	pb_b(push_swap, push_swap2, flag);
	sort_3_b(push_swap, flag);
	pa_b(push_swap, push_swap2, flag);
	ra_b(push_swap, flag);
}

void	sort_5_b(t_list **push_swap, t_list **push_swap2, int cnt, int flag)
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
		ra_b(push_swap, flag);
	else if (cnt == 2)
	{
		ra_b(push_swap, flag);
		ra_b(push_swap, flag);
	}
	else if (cnt == 3)
	{
		rra_b(push_swap, flag);
		rra_b(push_swap, flag);
	}
	else if (cnt == 4)
		rra_b(push_swap, flag);
	sort_5_sub_b(push_swap, push_swap2, flag);
}

void	sort_5_sub_b(t_list **push_swap, t_list **push_swap2, int flag)
{
	pb_b(push_swap, push_swap2, flag);
	sort_4_b(push_swap, push_swap2, flag);
	pa_b(push_swap, push_swap2, flag);
	ra_b(push_swap, flag);
}
