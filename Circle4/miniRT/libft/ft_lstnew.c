/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 01:33:05 by dasong            #+#    #+#             */
/*   Updated: 2023/11/27 18:12:16 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, t_figure num)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new_node)
		return (0);
	new_node->figure = num;
	new_node->content = content;
	new_node->next = 0;
	return (new_node);
}
