/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 03:53:22 by seykim            #+#    #+#             */
/*   Updated: 2023/07/10 19:30:26 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_info	*info_init_bonus(int argc, char **argv, char **envp)
{
	t_info	*info;
	int		i;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (0);
	info->fd_read = 0;
	info->fd_write = 0;
	info->flag = 0;
	info = order_init_bonus(info, argc, argv);
	info->flag = 0;
	i = -1;
	i = find_path_bonus(envp);
	if (i < 0)
		error_print_bonus("No PATH");
	info->path = ft_split2_bonus(envp[i] + 5, ':');
	return (info);
}

void	error_print_bonus(char *error)
{
	perror(error);
	exit(1);
}

int	find_path_bonus(char **envp)
{
	int	len;
	int	index;

	len = 0;
	index = 0;
	while (*envp)
	{
		if ((*envp)[index] == 'P' && (*envp)[index + 1] == 'A' \
		&& (*envp)[index + 2] == 'T' && (*envp)[index + 3] == 'H')
			break ;
		envp++;
		len++;
	}
	return (len);
}

t_info	*order_init_bonus(t_info *info, int argc, char **argv)
{
	int	i;

	i = 0;
	info->order = (char ***)malloc(sizeof(char ***) * (argc - 2));
	if (!info->order)
		error_print_bonus("Failed Malloc");
	info->len = (int *)malloc(sizeof(int) * (argc - 3));
	if (!info->len)
		error_print_bonus("Failed Malloc");
	while (i < argc - 3)
	{
		info->order[i] = ft_split_parse_bonus(argv[i + 2], ' ');
		if (!info->order[i])
			error_print_bonus("Failed Malloc");
		info->len[i] = ft_strlen_bonus(info->order[i][0]);
		i++;
	}
	info->order[i] = 0;
	return (info);
}

void	*ft_free3_bonus(char **arr)
{
	char	**temp;

	if (!arr)
		return (0);
	temp = arr;
	while (*temp)
	{
		if (*temp)
			free(*temp);
		temp++;
	}
	free(arr);
	return (0);
}
