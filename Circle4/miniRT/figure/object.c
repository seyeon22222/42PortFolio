/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:09:33 by seykim            #+#    #+#             */
/*   Updated: 2023/12/24 19:39:21 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "figure.h"
#include "../view/view.h"

t_obj_list	*object(int type, void *data, t_triple albedo)
{
	t_obj_list	*lst;

	lst = (t_obj_list *)malloc(sizeof(t_obj_list));
	if (!lst)
		print_error("No space to Malloc object");
	lst->type = type;
	lst->data = data;
	lst->next = 0;
	lst->albedo = albedo;
	return (lst);
}

void	obj_add(t_obj_list **lst, t_obj_list *new_element)
{
	t_obj_list	*curr;

	if (*lst == 0)
	{
		*lst = new_element;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new_element;
}

t_obj_list	*obj_last(t_obj_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
