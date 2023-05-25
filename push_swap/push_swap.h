/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:37:14 by seykim            #+#    #+#             */
/*   Updated: 2023/05/22 16:03:56 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>

//main
void	list_init(t_list **temp, t_list **push_swap, t_list **push_swap2);
int		list_insert(char **argv, t_list **temp, t_list **push_swap, int a);
int		*ft_array(t_list *push_swap, int l_size, int idx, int i);
void	error_check(int l_size, t_list **push_swap, \
t_list **push_swap2, int *arr);
void	sorted_arr(int l_size, t_list **push_swap, \
t_list **push_swap2, int flag);

//ordering func
void	sa(t_list **push_swap, int flag);
void	sb(t_list **push_swap, int flag);
void	ss(t_list **push_swap, t_list **push_swap2, int flag);
void	pa(t_list **push_swap, t_list **push_swap2, int flag);
void	pb(t_list **push_swap, t_list **push_swap2, int flag);
void	ra(t_list **push_swap, int flag);
void	rb(t_list **push_swap2, int flag);
void	rr(t_list **push_swap, t_list **push_swap2, int flag);
void	rra(t_list **push_swap, int flag);
void	rrb(t_list **push_swap, int flag);
void	rrr(t_list **push_swap, t_list **push_swap2, int flag);

//sorting 345
void	small_size(int l_size, t_list **push_swap, \
t_list **push_swap2, int flag);
void	sort_3(t_list **push_swap, int flag);
void	sort_4(t_list **push_swap, t_list **push_swap2, int flag);
void	sort_5(t_list **push_swap, t_list **push_swap2, int cnt, int flag);
void	sort_5_sub(t_list **push_swap, t_list **push_swap2, int flag);

//sorting else
void	send_clock(int l_size, t_list **push_swap, \
t_list **push_swap2, int flag);
void	send_sort(t_list **push_swap, t_list **push_swap2, int max, int flag);
void	send_sort2(t_list **push_swap, t_list **push_swap2, int big, int max);
void	send_sort3(t_list **push_swap, t_list **push_swap2, int big, int max);
int		max_position(t_list **push_swap2, int max);

//utils
int		sorted(t_list *push_swap, int *arr);
void	list_indexing(int l_size, t_list **push_swap, int *arr, int i);
void	swap(int *a, int *b);
int		bubble(int i, int l_size, int *arr);
void	error(void);
int		push_swap_space(char **argv, t_list **push_swap, t_list *temp, int a);
void	ft_free2(char **new);

#endif