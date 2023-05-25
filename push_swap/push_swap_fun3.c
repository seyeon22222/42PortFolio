/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fun3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:27:21 by seykim            #+#    #+#             */
/*   Updated: 2023/05/19 18:18:45 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **push_swap, int flag)
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

void	rb(t_list **push_swap2, int flag)
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

void	rr(t_list **push_swap, t_list **push_swap2, int flag)
{
	if (*push_swap == NULL || (*push_swap)->next == NULL \
	|| *push_swap2 == NULL || (*push_swap2)->next == NULL)
		return ;
	ra(push_swap, 1);
	rb(push_swap2, 1);
	if (flag == 0)
		write(1, "rr\n", 3);
}
