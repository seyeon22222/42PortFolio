/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:41:44 by seykim            #+#    #+#             */
/*   Updated: 2023/03/22 17:24:53 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lstsize;

	lstsize = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lstsize++;
		lst = lst->next;
	}
	return (lstsize);
}
