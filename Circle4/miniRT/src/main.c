/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:50:59 by seykim            #+#    #+#             */
/*   Updated: 2023/10/11 16:52:06 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void		arg_error(int argc, char **argv);
static t_info	*file_init(char **argv);
static void		check_arr(char *arr, t_info **temp);

int	main(int argc, char **argv)
{
	t_info	*info;

	arg_error(argc, argv);
	info = file_init(argv);
}

static void	arg_error(int argc, char **argv)
{
	int		idx;
	size_t	len;

	if (!(argc == 2 || argc == 3))
	{
		perror("Error\nArgument Error\n");
		exit(0);
	}
	idx = 0;
	len = ft_strlen(argv[1]);
	if (!(argv[1][len] == 't' && argv[1][len - 1] == 'r' \
	&& argv[1][len -2] == '.'))
	{
		perror("Error\nFile Name Error\n");
		exit(0);
	}
}

static t_info	*file_init(char **argv)
{
	t_info	*temp;
	int		fd;
	char	*arr;

	temp = (t_info *)malloc(sizeof(t_info));
	if (!temp)
	{
		perror("Error\nMalloc Fail");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	arr = get_next_line(fd);
	while (arr)
	{
		check_arr(arr, &temp);
		free(arr);
		arr = get_next_line(fd);
	}
}

static void	check_arr(char *arr, t_info **temp)
{
	char	**split;
	int		idx;

	split = ft_split(arr, 32);
	idx = 0;
	while (split[idx])
	{
		if (split[idx][0] == 'A' && !split[idx][1])
		{
			(*temp)->alight->num++;
			if ((*temp)->alight->num > 1)
				perror("Error\nCan't Multiple A");
		}
		else if (split[idx][0] == 'C' && !split[idx][1])
		{
			(*temp)->camera->num++;
			if ((*temp)->camera->num > 1)
				perror("Error\nCan't Multiple C");
		}
		else if (split[idx][0] == 'L' && !split[idx][1])
		{
			(*temp)->light->num++;
			if ((*temp)->light->num > 1)
				perror("Error\nCan't Multiple L");
		}
		else if (split[idx][0] == 's' && split[idx][1] == 'p' && !split[idx][2])
		{
			(*temp)->sphere->num++;
			if ((*temp)->sphere->num > 1)
				perror("Error\nCan't Multiple sp");
		}
		else if (split[idx][0] == 'p' && split[idx][1] == 'l' && !split[idx][2])
		{
			(*temp)->plat->num++;
			if ((*temp)->plat->num > 1)
				perror("Error\nCan't Multiple pl");
		}
		else if (split[idx][0] == 's' && split[idx][1] == 'q' && !split[idx][2])
		{
			(*temp)->rectangle->num++;
			if ((*temp)->rectangle->num > 1)
				perror("Error\nCan't Multiple sq");
		}
		else if (split[idx][0] == 'c' && split[idx][1] == 'y' && !split[idx][2])
		{
			(*temp)->columnar->num++;
			if ((*temp)->columnar->num > 1)
				perror("Error\nCan't Multiple cy");
		}
		else if (split[idx][0] == 't' && split[idx][1] == 'r' && !split[idx][2])
		{
			(*temp)->triangle->num++;
			if ((*temp)->triangle->num > 1)
				perror("Error\nCan't Multiple tr");
		}
		idx++;
	}
}
