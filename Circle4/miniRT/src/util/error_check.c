/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:03:57 by seykim            #+#    #+#             */
/*   Updated: 2023/11/23 20:56:37 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	print_error(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(1);
}

void	arg_error(int argc, char **argv)
{
	int		idx;
	size_t	len;

	if (!(argc == 2 || argc == 3))
		print_error("Argument Error");
	idx = 0;
	len = ft_strlen(argv[1]);
	if (!(argv[1][len - 1] == 't' && argv[1][len - 2] == 'r' \
	&& argv[1][len - 3] == '.'))
		print_error("File Name Error");
}

void	check_arr(char *arr, t_info **temp)
{
	int		idx;

	idx = 1;
	if (arr[0] == 'A' && arr[1] == 32)
		alight_check(temp, arr, idx);
	else if (arr[0] == 'C' && arr[1] == 32)
		camera_check(temp, arr, idx);
	else if (arr[0] == 'L' && arr[1] == 32)
		light_check(temp, arr, idx);
	else if (arr[0] == 's' && arr[1] == 'p' && arr[2] == 32)
		sphere_check(temp, arr, idx);
	else if (arr[0] == 'p' && arr[1] == 'l' && arr[2] == 32)
		plane_check(temp, arr, idx);
	else if (arr[0] == 'c' && arr[1] == 'y' && arr[2] == 32)
		cylinder_check(temp, arr, idx);
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
