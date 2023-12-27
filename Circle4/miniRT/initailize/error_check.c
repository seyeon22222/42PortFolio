/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:03:57 by seykim            #+#    #+#             */
/*   Updated: 2023/12/26 17:01:13 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initailize.h"
#include "../view/view.h"
#include "../util/get_next_line.h"

void	arg_error(int argc, char **argv)
{
	int		idx;
	size_t	len;

	if (!(argc == 2 || argc == 3))
		print_error("Argument Error");
	idx = 0;
	len = ft_strlen1(argv[1]);
	if (!(argv[1][len - 1] == 't' && argv[1][len - 2] == 'r' \
	&& argv[1][len - 3] == '.') || ft_strlen1(argv[1]) < 4)
		print_error("File Name Error");
}

void	free_split(char **res)
{
	int	idx;

	idx = 0;
	while (res[idx])
	{
		free(res[idx]);
		idx++;
	}
	free(res);
}
