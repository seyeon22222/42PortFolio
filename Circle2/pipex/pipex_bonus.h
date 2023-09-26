/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:05:05 by seykim            #+#    #+#             */
/*   Updated: 2023/07/10 19:29:35 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
	int		flag;
	char	***order;
	int		*len;
	char	**path;
}	t_info;

//pipex
t_info	*multi_cmd(int argc, char **argv, char **envp);
t_info	*here_doc_cmd(int argc, char **argv, char **envp);
t_info	*info_init_bonus(int argc, char **argv, char **envp);
char	**ft_split2_bonus(char const *s, char c);
void	*ft_free3_bonus(char **arr);
int		find_path_bonus(char **envp);
void	error_print_bonus(char *error);
void	carry_out_order1_bonus(t_info *info, int i, \
char **envp, char *order_name);
void	carry_out_check_bonus(t_info *info);
void	carry_out_execve_bonus(t_info *info, int i, \
char **envp, char *order_name);
void	carry_out_order2_bonus(t_info *info, int i, \
char **envp);
void	carry_out_check2_bonus(t_info *info);
void	carry_out_execve2_bonus(t_info *info, int i, char **envp, int j);
int		ft_strlen_bonus(const char *s);
char	*ft_strjoin_bonus(char *s1, char *s2);
t_info	*order_init_bonus(t_info *info, int argc, char **argv);
void	*free3_bonus(char ***arr);
void	*free_info(t_info *info);
void	here_doc_set(t_info *info, char **argv);

//split
int		check_argv_bonus(char *argv);
char	**ft_split_parse_bonus(char const *s, char c);
void	change_char_bonus(char ch, int *flag, char *c, int *num);
char	*abc_bonus(int start, int end, char *str);
int		find_cs_bonus(char c, char charset);
int		size_count_bonus(char *str, char c);
char	**ft_free_bonus(char **newstr, int idx);
void	set_arr_bonus(char const *s, int *arr, char c, char **newstr);

//get_next_line
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
char	*get_next_line(int fd);
char	*read_line(int fd, int x, char **arr, char **res);
char	*print_arr(char **res);
char	*print_arr2(char **temp, char **temp2, char **res, int len);
void	*ft_free(char **arr);
#endif
