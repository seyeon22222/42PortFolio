/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 05:29:12 by seykim            #+#    #+#             */
/*   Updated: 2023/07/11 16:51:21 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	carry_out_order1_bonus(t_info *info, int i, \
char **envp, char *order_name)
{
	pid_t	cmd1;

	cmd1 = fork();
	if (cmd1 < 0)
		error_print_bonus("no fork assign");
	else if (cmd1 == 0)
	{
		carry_out_check_bonus(info);
		carry_out_execve_bonus(info, i, envp, order_name);
		if (info->flag != 2)
			error_print_bonus("order error");
	}
	else
	{
		close(info->fds[WRITE]);
		if (dup2(info->fds[READ], READ) < 0)
			error_print_bonus("impossible file descript");
		close(info->fds[READ]);
		info->flag = 1;
	}
}

void	carry_out_check_bonus(t_info *info)
{
	if (info->flag != 1)
	{
		close(info->fds[READ]);
		if ((dup2(info->fds[WRITE], WRITE) < 0) \
		|| (dup2(info->fd_read, READ) < 0))
			error_print_bonus("impossible file descript");
		close(info->fds[WRITE]);
		close(info->fd_read);
		close(info->fd_write);
	}
	else
	{
		close(info->fds[READ]);
		if ((dup2(info->fds[WRITE], WRITE) < 0))
			error_print_bonus("impossible file descript");
		close(info->fds[WRITE]);
		close(info->fd_read);
		close(info->fd_write);
	}
}

void	carry_out_execve_bonus(t_info *info, int i, \
char **envp, char *order_name)
{
	int	j;

	j = 0;
	if (access(info->order[i][0], X_OK) != -1)
	{
		info->flag = 2;
		execve(info->order[i][0], info->order[i], envp);
	}
	while (info->path[j])
	{
		order_name = (char *)malloc(sizeof(char) * info->len[i] + \
		ft_strlen_bonus(info->path[j]) + 1);
		if (!order_name)
			return ;
		order_name = ft_strjoin_bonus(info->path[j], info->order[i][0]);
		if (access(order_name, X_OK) != -1)
		{
			info->flag = 2;
			execve(order_name, info->order[i], envp);
		}
		free(order_name);
		j++;
	}
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	char	*new_str;
	int		idx;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen_bonus(s1);
	len2 = ft_strlen_bonus(s2);
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

int	ft_strlen_bonus(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}
