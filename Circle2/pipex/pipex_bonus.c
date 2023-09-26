/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:56:22 by seykim            #+#    #+#             */
/*   Updated: 2023/08/02 17:08:43 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;

	if (argc < 5)
		error_print_bonus("open");
	if (argv[1][0] == 'h' && argv[1][1] == 'e' && argv[1][2] == 'r' \
	&& argv[1][3] == 'e' && argv[1][4] == '_' && argv[1][5] == 'd' \
	&& argv[1][6] == 'o' && argv[1][7] == 'c' && argv[1][8] == 0)
		info = here_doc_cmd(argc, argv, envp);
	else
		info = multi_cmd(argc, argv, envp);
	free_info(info);
	return (0);
}

t_info	*here_doc_cmd(int argc, char **argv, char **envp)
{
	t_info	*info;
	int		i;

	info = info_init_bonus(argc, argv, envp);
	here_doc_set(info, argv);
	info->fd_read = open("temp", O_RDONLY);
	if (dup2(info->fd_read, READ) < 0)
		error_print_bonus("STDIN dup_error");
	info->fd_write = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (info->fd_write < 0)
		error_print_bonus("write");
	i = 0;
	while (++i < argc - 4)
	{
		if (pipe(info->fds) < 0)
			error_print_bonus("no pipe assign");
		carry_out_order1_bonus(info, i, envp, 0);
	}
	carry_out_order2_bonus(info, (argc - 4), envp);
	close(info->fd_read);
	close(info->fd_write);
	unlink("temp");
	return (info);
}

void	here_doc_set(t_info *info, char **argv)
{
	char	*gnl;

	info->fd_read = open("temp", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (info->fd_read < 0)
		error_print_bonus("open");
	if (dup2(info->fd_read, WRITE) < 0)
		error_print_bonus("STDOUT dup_error");
	ft_putstr_fd("pipe heredoc> ", 0);
	gnl = get_next_line(0);
	while (gnl > 0)
	{
		if ((ft_strlen(gnl) - 1) == ft_strlen(argv[2]) \
		&& ft_strncmp(argv[2], gnl, ft_strlen(gnl) - 1) == 0)
			break ;
		write(info->fd_read, gnl, ft_strlen(gnl));
		free(gnl);
		ft_putstr_fd("pipe heredoc> ", 0);
		gnl = get_next_line(0);
	}
	free(gnl);
	close(info->fd_read);
}

t_info	*multi_cmd(int argc, char **argv, char **envp)
{
	t_info	*info;
	int		i;

	info = info_init_bonus(argc, argv, envp);
	info->fd_read = open(argv[1], O_RDONLY);
	if (info->fd_read == -1)
		perror("open");
	info->fd_write = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (info->fd_write == -1)
		error_print_bonus("write");
	i = -1;
	while (++i < argc - 4)
	{
		if (pipe(info->fds) == -1)
			error_print_bonus("no pipe assign");
		carry_out_order1_bonus(info, i, envp, 0);
	}
	carry_out_order2_bonus(info, (argc - 4), envp);
	close(info->fd_read);
	close(info->fd_write);
	return (info);
}

void	*free_info(t_info *info)
{
	free3_bonus(info->order);
	ft_free3_bonus(info->path);
	free(info->len);
	free(info);
	return (0);
}
