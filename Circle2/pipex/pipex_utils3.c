/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 05:29:39 by seykim            #+#    #+#             */
/*   Updated: 2023/07/04 18:16:24 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	carry_out_order2(t_info *info, int i, char **envp, char *order_name2)
{
	pid_t	cmd2;

	cmd2 = fork();
	info->flag = 0;
	if (cmd2 < 0)
		error_print("no fork assign");
	else if (cmd2 == 0)
	{	
		carry_out_check2(info);
		carry_out_execve2(info, i, envp, order_name2);
	}
	else
		waitpid(cmd2, 0, 0);
}

void	carry_out_check2(t_info *info)
{
	close(info->fds[WRITE]);
	if (dup2(info->fd_write, WRITE) < 0)
		error_print("impossible file descript");
	close(info->fds[READ]);
}

void	carry_out_execve2(t_info *info, int i, char **envp, char *order_name2)
{
	if (access(info->order2[0], X_OK) != -1)
	{
		info->flag = 1;
		execve(info->order2[0], info->order2, envp);
	}
	while (info->path[++i])
	{
		order_name2 = (char *)malloc(sizeof(char) * \
		info->len2 + ft_strlen(info->path[i]) + 1);
		if (!order_name2)
			return ;
		order_name2 = ft_strjoin(info->path[i], info->order2[0]);
		if (access(order_name2, X_OK) != -1)
		{
			info->flag = 1;
			execve(order_name2, info->order2, envp);
		}
		free(order_name2);
	}
	if (info->flag != 1)
		error_print("order2 error");
}

void	*ft_free(char **arr)
{
	if (*arr)
		free(*arr);
	*arr = 0;
	return (0);
}

void	*ft_free3(char **arr)
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
