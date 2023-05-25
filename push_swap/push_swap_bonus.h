/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:37:14 by seykim            #+#    #+#             */
/*   Updated: 2023/05/22 16:18:27 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

//main
void	list_init_b(t_list **temp, t_list **push_swap, t_list **push_swap2);
int		list_insert_b(char **argv, t_list **temp, t_list **push_swap, int a);
int		*ft_array_b(t_list *push_swap, int l_size, int idx, int i);
void	error_check_bonus(int l_size, t_list **push_swap, int *arr);
void	sorted_arr_b(int l_size, t_list **push_swap, \
t_list **push_swap2, int flag);

//ordering func
void	sa_b(t_list **push_swap, int flag);
void	sb_b(t_list **push_swap, int flag);
void	ss_b(t_list **push_swap, t_list **push_swap2, int flag);
void	pa_b(t_list **push_swap, t_list **push_swap2, int flag);
void	pb_b(t_list **push_swap, t_list **push_swap2, int flag);
void	ra_b(t_list **push_swap, int flag);
void	rb_b(t_list **push_swap2, int flag);
void	rr_b(t_list **push_swap, t_list **push_swap2, int flag);
void	rra_b(t_list **push_swap, int flag);
void	rrb_b(t_list **push_swap, int flag);
void	rrr_b(t_list **push_swap, t_list **push_swap2, int flag);

//sorting 345
void	small_size_b(int l_size, t_list **push_swap, \
t_list **push_swap2, int flag);
void	sort_3_b(t_list **push_swap, int flag);
void	sort_4_b(t_list **push_swap, t_list **push_swap2, int flag);
void	sort_5_b(t_list **push_swap, \
t_list **push_swap2, int cnt, int flag);
void	sort_5_sub_b(t_list **push_swap, t_list **push_swap2, int flag);

//sorting else
void	send_clock_b(int l_size, t_list **push_swap, \
t_list **push_swap2, int flag);
void	send_sort_b(t_list **push_swap, t_list **push_swap2, int max, int flag);
void	send_sort2_b(t_list **push_swap, t_list **push_swap2, int big, int max);
void	send_sort3_b(t_list **push_swap, t_list **push_swap2, int big, int max);
int		max_position(t_list **push_swap2, int max);

//utils
int		sorted_b(t_list *push_swap, int *arr);
void	list_indexing_b(int l_size, t_list **push_swap, int *arr, int i);
void	swap_b(int *a, int *b);
int		bubble_b(int i, int l_size, int *arr);
void	error_b(void);
int		push_swap_space_b(char **argv, t_list **push_swap, t_list *temp, int a);
void	ft_free2_b(char **new);

//get_next_line
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*print_arr(char **res);
char	*ft_strdup(char *src);
void	*ft_free(char **arr);
char	*read_line(int fd, int x, char **arr, char **res);
char	*print_arr2(char **temp, char **temp2, char **res, int len);
t_list	*order_check(t_list **push_swap, t_list **push_swap2, int flag);
void	order1(t_list **push_swap, t_list **push_swap2, char *order, int flag);
int		order2(t_list **push_swap, t_list **push_swap2, char *order, int flag);

#endif