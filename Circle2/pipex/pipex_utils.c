/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 03:53:22 by seykim            #+#    #+#             */
/*   Updated: 2023/07/10 21:13:16 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_info	*info_init(char **argv, char **envp)
{
	t_info	*info;
	int		i;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (0);
	info->fd_read = 0;
	info->fd_write = 0;
	info->flag = 0;
	info->order1 = ft_split_parse(argv[2], ' ');
	info->order2 = ft_split_parse(argv[3], ' ');
	if (!info->order1 || !info->order2)
		return (0);
	info->len1 = ft_strlen(info->order1[0]);
	info->len2 = ft_strlen(info->order2[0]);
	info->flag = 0;
	i = -1;
	i = find_path(envp);
	if (i < 0)
		error_print("No PATH");
	info->path = ft_split2(envp[i] + 5, ':');
	return (info);
}

void	error_print(char *error)
{
	perror(error);
	exit(1);
}

int	find_path(char **envp)
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

int	check_argv(char *argv)
{
	int	i;
	int	cnt_i;
	int	cnt_j;

	i = 0;
	cnt_i = 0;
	cnt_j = 0;
	while (argv[i])
	{
		if (argv[i] == '\'')
			cnt_i++;
		if (argv[i] == '"')
			cnt_j++;
		i++;
	}
	if (cnt_i >= 2)
		return (1);
	if (cnt_j >= 2)
		return (1);
	else
		return (0);
}
