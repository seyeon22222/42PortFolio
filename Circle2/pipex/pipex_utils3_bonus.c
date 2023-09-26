/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 05:29:39 by seykim            #+#    #+#             */
/*   Updated: 2023/08/02 18:08:28 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	carry_out_order2_bonus(t_info *info, int i, char **envp)
{
	pid_t	cmd2;

	cmd2 = fork();
	info->flag = 0;
	if (cmd2 < 0)
		error_print_bonus("no fork assign");
	else if (cmd2 == 0)
	{	
		carry_out_check2_bonus(info);
		carry_out_execve2_bonus(info, i, envp, -1);
	}
	else
	{
		waitpid(cmd2, 0, 0);
	}
}

void	carry_out_check2_bonus(t_info *info)
{
	close(info->fds[WRITE]);
	if (dup2(info->fd_write, WRITE) < 0)
		error_print_bonus("impossible file descript");
	close(info->fds[READ]);
}

void	carry_out_execve2_bonus(t_info *info, int i, char **envp, int j)
{
	char	*order_name2;

	if (access(info->order[i][0], X_OK) != -1)
	{
		info->flag = 1;
		execve(info->order[i][0], info->order[i], envp);
	}
	while (info->path[++j])
	{
		order_name2 = (char *)malloc(sizeof(char) * \
		info->len[i] + ft_strlen_bonus(info->path[j]) + 1);
		if (!order_name2)
			return ;
		order_name2 = ft_strjoin_bonus(info->path[j], info->order[i][0]);
		if (access(order_name2, X_OK) != -1)
		{
			info->flag = 1;
			execve(order_name2, info->order[i], envp);
		}
	}
	if (info->flag != 1)
		error_print_bonus("order error");
}

int	check_argv_bonus(char *argv)
{
	int	i;
	int	cnt_i;

	i = 0;
	cnt_i = 0;
	while (argv[i])
	{
		if (argv[i] == '\'')
			cnt_i++;
		i++;
	}
	if (cnt_i >= 2)
		return (1);
	else
		return (0);
}

void	*free3_bonus(char ***arr)
{
	char	***temp;
	int		i;

	if (!arr)
		return (0);
	temp = arr;
	i = 0;
	while (temp[i])
	{
		ft_free3_bonus(temp[i]);
		i++;
	}
	free(temp);
	return (0);
}
