/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:45:05 by seykim            #+#    #+#             */
/*   Updated: 2023/09/25 19:39:55 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000 + now.tv_usec / 1000));
}

void	print_msg(t_philo *philo, int id, const char *str, int flag)
{
	long long	time;

	if (flag == 1)
		pthread_mutex_unlock(&philo->share->end_mutex);
	usleep(100);
	pthread_mutex_lock(&philo->share->end_mutex);
	pthread_mutex_lock(&philo->share->print_mutex);
	if (philo->share->dead_flag != 0 && flag == 0)
	{
		pthread_mutex_unlock(&philo->share->end_mutex);
		pthread_mutex_unlock(&philo->share->print_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->share->end_mutex);
	time = (get_time() - philo->share->start);
	printf("%lld %d %s\n", time, id + 1, str);
	pthread_mutex_unlock(&philo->share->print_mutex);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = get_time();
	while (get_time() - time < ms)
		usleep(100);
}

void	all_free(t_share *share, t_philo *philo)
{
	int	cnt;

	cnt = 0;
	free(share->fork);
	pthread_mutex_destroy(&share->print_mutex);
	pthread_mutex_destroy(&share->end_mutex);
	while (cnt < philo->info.philo_nums)
	{
		pthread_mutex_destroy(&share->fork[cnt]);
		cnt++;
	}
	free(philo);
}
