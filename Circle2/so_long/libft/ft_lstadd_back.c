/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:47:59 by seykim            #+#    #+#             */
/*   Updated: 2023/05/10 18:27:18 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*find;

	if (!lst)
		return ;
	find = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (find)
		{
			if (find->next == NULL)
				break ;
			find = find->next;
		}
		find->next = new;
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
// 		ft_lstadd_back(&test, new);
// 	}
// 	while (test)
// 	{
// 		printf("%d \t", *(int*)test->content);
// 		test = test->next;
// 	}
// }