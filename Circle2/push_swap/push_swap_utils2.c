/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:53:49 by seykim            #+#    #+#             */
/*   Updated: 2023/05/22 16:56:30 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_insert(char **argv, t_list **temp, t_list **push_swap, int a)
{
	int	l_size;

	l_size = 0;
	while (argv[++a])
	{
		if (ft_isspace(argv[a]))
			l_size += push_swap_space(argv, push_swap, (*temp), a);
		else
		{
			*temp = ft_lstnew(ft_atoi(argv[a]));
			ft_lstadd_back(push_swap, (*temp));
			(*temp)->next = NULL;
			l_size++;
		}
	}
	return (l_size);
}

void	list_init(t_list **temp, t_list **push_swap, t_list **push_swap2)
{
	*push_swap = NULL;
	*push_swap2 = NULL;
	*temp = NULL;
}

void	sorted_arr(int l_size, t_list **push_swap, \
t_list **push_swap2, int flag)
{
	if (l_size > 5)
	{
		send_clock(l_size, push_swap, push_swap2, flag);
		send_sort(push_swap, push_swap2, l_size, flag);
	}
	else
		small_size(l_size, push_swap, push_swap2, flag);
}

int	*ft_array(t_list *push_swap, int l_size, int idx, int i)
{
	int		*arr;
	int		flag;

	arr = (int *)malloc(sizeof(int) * l_size);
	if (!arr)
		return (0);
	while (push_swap != NULL)
	{
		arr[idx++] = push_swap->content;
		push_swap = push_swap->next;
	}
	flag = bubble(i, l_size, arr);
	if (flag == 1)
		error();
	return (arr);
}

int	push_swap_space(char **argv, t_list **push_swap, t_list *temp, int a)
{
	char	**new;
	int		i;

	new = ft_split(argv[a], ' ');
	i = 0;
	while (new[i])
	{
		temp = ft_lstnew(ft_atoi(new[i]));
		ft_lstadd_back(push_swap, temp);
		temp->next = NULL;
		i++;
	}
	ft_free2(new);
	return (i);
}
