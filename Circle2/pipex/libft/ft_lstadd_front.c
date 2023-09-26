/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:30:50 by seykim            #+#    #+#             */
/*   Updated: 2023/03/23 19:16:35 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}	
}

// #include <stdio.h>
// #include <stdlib.h>
// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*newnode;
// 	newnode = (t_list *)malloc(sizeof(t_list));
// 	if (!newnode)
// 		return (NULL);
// 	newnode->content = content;
// 	newnode->next = NULL;
// 	return (newnode);
// }
// int main()
// {
// 	t_list	*test;
// 	t_list	*new;
// 	int *data1 = malloc(sizeof(int));
// 	*data1 = 5;
// 	test = ft_lstnew(data1);
// 	for (int i = 0; i< 10; i++)
// 	{
// 		int *data = malloc(sizeof(int));
// 		*data =i ;
// 		new = ft_lstnew(data);
// 		ft_lstadd_front(&test, new);
// 	}
// 	while (test)
// 	{
// 		printf("%d \t", *(int*)test->content);
// 		test = test->next;
// 	}
// }