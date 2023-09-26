/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:17:52 by seykim            #+#    #+#             */
/*   Updated: 2023/03/22 17:22:23 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	lstadd(t_list **resnode, t_list **finode, t_list *newnode);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*resnode;
	t_list	*finode;

	resnode = NULL;
	finode = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		newnode = (t_list *)malloc(sizeof(t_list));
		if (!newnode)
		{
			ft_lstclear(&finode, del);
			return (NULL);
		}
		newnode->content = (*f)(lst->content);
		newnode->next = NULL;
		lst = lst->next;
		lstadd(&resnode, &finode, newnode);
	}
	return (finode);
}

static void	lstadd(t_list **resnode, t_list **finode, t_list *newnode)
{
	t_list	*find;

	if (!(*resnode))
	{
		*resnode = newnode;
		*finode = *resnode;
	}
	else
	{
		find = *resnode;
		while (find)
		{
			if (find->next == NULL)
				break ;
			find = find->next;
		}
		find->next = newnode;
	}
}
