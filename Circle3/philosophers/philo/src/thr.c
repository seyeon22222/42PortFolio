/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:50:07 by seykim            #+#    #+#             */
/*   Updated: 2023/09/25 19:41:58 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	number_of_two_or_more(t_philo *philo);
static int	pick_fork(t_philo *philo);

void	*thr_func(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	if (philo->info.philo_nums == 1)
	{
		pthread_mutex_lock(&philo->share->fork[philo->left_fork]);
		print_msg(philo, philo->self_num, "has taken a fork", 0);
		ft_usleep(philo->info.time_to_die);
		pthread_mutex_unlock(&philo->share->fork[philo->left_fork]);
	}
	else
		number_of_two_or_more(philo);
	return (0);
}

static void	number_of_two_or_more(t_philo *philo)
{
	if (philo->self_num % 2)
		ft_usleep(philo->info.time_to_eat);
	pthread_mutex_lock(&philo->share->check);
	while (philo->share->dead_flag == 0)
	{
		pthread_mutex_unlock(&philo->share->check);
		if (pick_fork(philo))
			break ;
		print_msg(philo, philo->self_num, "is sleeping", 0);
		ft_usleep(philo->info.time_to_sleep);
		print_msg(philo, philo->self_num, "is thinking", 0);
		usleep(100);
		pthread_mutex_lock(&philo->share->check);
	}
	pthread_mutex_unlock(&philo->share->check);
}

static int	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->share->fork[philo->left_fork]);
	print_msg(philo, philo->self_num, "has taken a fork", 0);
	pthread_mutex_lock(&philo->share->fork[philo->right_fork]);
	print_msg(philo, philo->self_num, "has taken a fork", 0);
	print_msg(philo, philo->self_num, "is eating", 0);
	pthread_mutex_lock(&philo->share->check);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->share->check);
	usleep(100);
	pthread_mutex_lock(&philo->share->check);
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->share->check);
	ft_usleep(philo->info.time_to_eat);
	pthread_mutex_unlock(&philo->share->fork[philo->right_fork]);
	pthread_mutex_unlock(&philo->share->fork[philo->left_fork]);
	if (philo->info.must_eat_count == philo->eat_cnt)
	{
		pthread_mutex_lock(&philo->share->end_mutex);
		philo->share->finish++;
		pthread_mutex_unlock(&philo->share->end_mutex);
		return (1);
	}
	return (0);
}
