/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fun2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:26:44 by seykim            #+#    #+#             */
/*   Updated: 2023/05/19 18:16:39 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **push_swap, t_list **push_swap2, int flag)
{
	t_list	*temp;

	if (push_swap2 != NULL && *push_swap2 != NULL)
	{
		temp = *push_swap2;
		*push_swap2 = temp->next;
		temp->next = *push_swap;
		*push_swap = temp;
	}
	if (flag == 0)
		write(1, "pa\n", 3);
}

void	pb(t_list **push_swap, t_list **push_swap2, int flag)
{
	t_list	*temp;

	if (push_swap != NULL && *push_swap != NULL)
	{
		temp = *push_swap;
		*push_swap = temp->next;
		temp->next = *push_swap2;
		*push_swap2 = temp;
	}
	if (flag == 0)
		write(1, "pb\n", 3);
}
