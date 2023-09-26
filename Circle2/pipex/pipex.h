/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:05:05 by seykim            #+#    #+#             */
/*   Updated: 2023/07/04 21:55:06 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ 0
# define WRITE 1

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "sys/wait.h"

typedef struct s_info
{
	int		fd_read;
	int		fd_write;
	int		fds[2];
	int		len1;
	int		len2;
	int		flag;
	char	**order1;
	char	**order2;
	char	**path;
}	t_info;

//pipex
t_info	*info_init(char **argv, char **envp);
char	**ft_split2(char const *s, char c);
void	*ft_free3(char **arr);
int		find_path(char **envp);
void	error_print(char *error);
void	carry_out_order1(t_info *info, int i, char **envp, char *order_name);
void	carry_out_check(t_info *info);
void	carry_out_execve(t_info *info, int i, char **envp, char *order_name);
void	carry_out_order2(t_info *info, int i, char **envp, char *order_name2);
void	carry_out_check2(t_info *info);
void	carry_out_execve2(t_info *info, int i, char **envp, char *order_name2);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_free(char **arr);
int		check_argv(char *argv);

//split
int		check_argv(char *argv);
char	**ft_split_parse(char const *s, char c);
void	change_char(char ch, int *flag, char *c, int *num);
char	*abc(int start, int end, char *str);
int		find_cs(char c, char charset);
int		size_count(char *str, char c);
char	**ft_free5(char **newstr, int idx);
void	set_arr(char const *s, int *arr, char c, char **newstr);
#endif