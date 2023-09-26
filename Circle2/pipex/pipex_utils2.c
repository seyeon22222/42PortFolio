/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 05:29:12 by seykim            #+#    #+#             */
/*   Updated: 2023/08/16 15:52:13 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	carry_out_order1(t_info *info, int i, char **envp, char *order_name)
{
	pid_t	cmd1;

	cmd1 = fork();
	if (cmd1 < 0)
		error_print("no fork assign");
	else if (cmd1 == 0)
	{
		carry_out_check(info);
		carry_out_execve(info, i, envp, order_name);
		if (info->flag != 1)
			error_print("order error");
	}
	else
	{
		close(info->fds[WRITE]);
		if (dup2(info->fds[READ], READ) < 0)
			error_print("impossible file descript");
		close(info->fds[READ]);
	}
}

void	carry_out_check(t_info *info)
{
	close(info->fds[READ]);
	if ((dup2(info->fds[WRITE], WRITE) < 0) || (dup2(info->fd_read, READ) < 0))
		error_print("impossible file descript");
	close(info->fds[WRITE]);
	close(info->fd_read);
	close(info->fd_write);
}

void	carry_out_execve(t_info *info, int i, char **envp, char *order_name)
{
	if (access(info->order1[0], X_OK) != -1)
	{
		info->flag = 1;
		execve(info->order1[0], info->order1, envp);
	}
	while (info->path[++i])
	{
		order_name = (char *)malloc(sizeof(char) * info->len1 + \
		ft_strlen(info->path[i]) + 1);
		if (!order_name)
			return ;
		order_name = ft_strjoin(info->path[i], info->order1[0]);
		if (access(order_name, X_OK) != -1)
		{
			info->flag = 1;
			execve(order_name, info->order1, envp);
		}
		free(order_name);
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	idx;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new_str)
		return (0);
	idx = -1;
	while (++idx < len1 + len2)
	{
		if (idx < len1)
			new_str[idx] = s1[idx];
		else if ((idx >= len1) && idx < (len1 + len2))
			new_str[idx] = s2[idx - len1];
	}
	new_str[idx] = 0;
	return (new_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}
