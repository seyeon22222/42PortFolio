/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_func5.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:27:21 by seykim            #+#    #+#             */
/*   Updated: 2023/05/19 17:38:12 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_b(t_list **push_swap, int flag)
{
	t_list	*temp;
	t_list	*new;

	if (*push_swap == NULL || (*push_swap)->next == NULL)
		return ;
	temp = *push_swap;
	*push_swap = (*push_swap)->next;
	new = ft_lstnew(temp->content);
	free(temp);
	ft_lstadd_back(push_swap, new);
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rb_b(t_list **push_swap2, int flag)
{
	t_list	*temp;
	t_list	*new;

	if (*push_swap2 == NULL || (*push_swap2)->next == NULL)
		return ;
	temp = *push_swap2;
	*push_swap2 = (*push_swap2)->next;
	new = ft_lstnew(temp->content);
	free(temp);
	ft_lstadd_back(push_swap2, new);
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rr_b(t_list **push_swap, t_list **push_swap2, int flag)
{
	if (*push_swap == NULL || (*push_swap)->next == NULL \
	|| *push_swap2 == NULL || (*push_swap2)->next == NULL)
		return ;
	ra_b(push_swap, 1);
	rb_b(push_swap, 1);
	if (flag == 0)
		write(1, "rr\n", 3);
}
