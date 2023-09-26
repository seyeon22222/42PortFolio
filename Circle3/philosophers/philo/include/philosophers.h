/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:25:46 by seykim            #+#    #+#             */
/*   Updated: 2023/09/12 17:25:46 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_info
{
	int	philo_nums;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_count;
}	t_info;

typedef struct s_share
{
	long long				start;
	int						dead_flag;
	int						finish;
	int						flag;
	pthread_mutex_t			print_mutex;
	pthread_mutex_t			end_mutex;
	pthread_mutex_t			check;
	pthread_mutex_t			*fork;
}	t_share;

typedef struct s_philo
{
	int			self_num;
	int			left_fork;
	int			right_fork;
	int			eat_cnt;
	long long	last_eat;
	t_share		*share;
	t_info		info;
	pthread_t	thr;
}	t_philo;

int			ft_atoi(const char *str);
int			info_init(char **argv, t_info *info);
int			share_init(t_share *share, t_info *info);
int			philo_init(t_info *info, t_share *share, t_philo **philo);
void		*ft_calloc(size_t count, size_t size);
void		*thr_func(void *temp);
void		print_msg(t_philo *philo, int id, const char *str, int flag);
void		philo_eat(t_philo *philo);
void		philo_sleep_thinking(t_philo *philo);
void		ft_usleep(int ms);
void		all_free(t_share *share, t_philo *philo);
long long	get_time(void);

#endif