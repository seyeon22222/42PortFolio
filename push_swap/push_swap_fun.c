/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:25:58 by seykim            #+#    #+#             */
/*   Updated: 2023/05/19 18:54:16 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **push_swap, int flag)
{
	int	temp;

	if (push_swap != NULL && *push_swap != NULL && (*push_swap)->next != NULL)
	{
		temp = (*push_swap)->content;
		(*push_swap)->content = (*push_swap)->next->content;
		(*push_swap)->next->content = temp;
	}
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	sb(t_list **push_swap2, int flag)
{
	int	temp;

	if (push_swap2 != NULL && *push_swap2 != NULL \
	&& (*push_swap2)->next != NULL)
	{
		temp = (*push_swap2)->content;
		(*push_swap2)->content = (*push_swap2)->next->content;
		(*push_swap2)->next->content = temp;
	}
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	ss(t_list **push_swap, t_list **push_swap2, int flag)
{
	int	temp;
	int	temp2;

	if (push_swap != NULL && *push_swap != NULL && (*push_swap)->next != NULL \
	&& push_swap2 != NULL && *push_swap2 != NULL && (*push_swap2)->next != NULL)
	{
		temp = (*push_swap)->content;
		(*push_swap)->content = (*push_swap)->next->content;
		(*push_swap)->next->content = temp;
		temp2 = (*push_swap2)->content;
		(*push_swap2)->content = (*push_swap2)->next->content;
		(*push_swap2)->next->content = temp2;
	}
	if (flag == 0)
		write(1, "ss\n", 3);
}

void	list_indexing(int l_size, t_list **push_swap, int *arr, int i)
{
	t_list	*temp;

	temp = *push_swap;
	while (i < l_size)
	{
		(*push_swap) = temp;
		while (*push_swap != NULL)
		{
			if (arr[i] == (*push_swap)->content)
			{
				(*push_swap)->content = i;
				arr[i] = i;
			}
			(*push_swap) = (*push_swap)->next;
		}
		i++;
	}
	(*push_swap) = temp;
}

int	sorted(t_list *push_swap, int *arr)
{
	int	temp;

	temp = arr[0];
	while (push_swap != NULL)
	{
		if (temp == push_swap->content)
			temp++;
		else
			return (1);
		push_swap = push_swap->next;
	}
	return (0);
}
