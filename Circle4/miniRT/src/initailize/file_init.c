/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:58:28 by seykim            #+#    #+#             */
/*   Updated: 2023/11/27 19:35:16 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_list	*file_init(char **argv)
{
	t_list	*temp;
	int		fd;
	char	*arr;

	temp = ft_lstnew(0, 0);
	fd = open(argv[1], O_RDONLY);
	arr = get_next_line(fd);
	while (arr)
	{
		check_arr(arr, temp);
		free(arr);
		arr = get_next_line(fd);
	}
	return (temp);
}
