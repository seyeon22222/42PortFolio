/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:56:22 by seykim            #+#    #+#             */
/*   Updated: 2023/07/11 17:00:20 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;

	if (argc != 5)
		error_print("open");
	info = info_init(argv, envp);
	info->fd_read = open(argv[1], O_RDONLY);
	if (info->fd_read == -1)
		perror("open");
	info->fd_write = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (info->fd_write == -1)
		error_print("write");
	if (pipe(info->fds) == -1)
		error_print("no pipe assign");
	carry_out_order1(info, -1, envp, 0);
	carry_out_order2(info, -1, envp, 0);
	ft_free3(info->order1);
	ft_free3(info->order2);
	ft_free3(info->path);
	close(info->fd_read);
	close(info->fd_write);
	return (0);
}
