/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:20:36 by seykim            #+#    #+#             */
/*   Updated: 2023/09/25 19:42:19 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	check_eat_cnt(t_philo *philo);
static int	check_die_philo(t_philo *philo);
static int	thr_start(t_philo *philo);
static void	dead_check(t_philo *philo);

int	main(int argc, char **argv)
{
	t_info	info;
	t_share	share;
	t_philo	*philo;

	if (!(argc == 5 || argc == 6))
	{
		printf("Arguments error");
		return (1);
	}
	if (info_init(argv, &info))
		return (1);
	if (share_init(&share, &info))
		return (1);
	if (philo_init(&info, &share, &philo))
		return (1);
	if (thr_start(philo))
		return (1);
	all_free(&share, philo);
}

static int	thr_start(t_philo *philo)
{
	int	cnt;

	cnt = 0;
	while (cnt < philo->info.philo_nums)
	{
		philo[cnt].last_eat = get_time();
		if (pthread_create(&philo[cnt].thr, NULL, thr_func, &philo[cnt]))
		{
			printf("Can't Make Thread");
			return (1);
		}
		cnt++;
	}
	dead_check(philo);
	cnt = 0;
	while (cnt < philo->info.philo_nums)
	{
		pthread_join(philo[cnt].thr, NULL);
		cnt++;
	}
	return (0);
}

static void	dead_check(t_philo *philo)
{
	int	temp;

	pthread_mutex_lock(&philo->share->check);
	pthread_mutex_lock(&philo->share->end_mutex);
	while (philo->share->dead_flag == 0)
	{
		if (check_eat_cnt(philo))
			return ;
		temp = check_die_philo(philo);
		if (temp)
			return ;
		pthread_mutex_unlock(&philo->share->check);
		pthread_mutex_unlock(&philo->share->end_mutex);
		usleep(100);
		pthread_mutex_lock(&philo->share->check);
		pthread_mutex_lock(&philo->share->end_mutex);
	}
	pthread_mutex_unlock(&philo->share->check);
	pthread_mutex_unlock(&philo->share->end_mutex);
}

static int	check_eat_cnt(t_philo *philo)
{
	if (philo->eat_cnt != 0 && \
	(philo->share->finish == philo->info.philo_nums))
	{
		philo->share->dead_flag = 1;
		pthread_mutex_unlock(&philo->share->check);
		pthread_mutex_unlock(&philo->share->end_mutex);
		return (1);
	}
	return (0);
}

static int	check_die_philo(t_philo *philo)
{
	int			cnt;
	long long	now;

	cnt = 0;
	while (cnt < philo->info.philo_nums)
	{
		now = get_time();
		if ((now - philo[cnt].last_eat) >= philo->info.time_to_die)
		{
			philo->share->dead_flag = 1;
			philo->share->flag++;
			if (philo->share->flag == 1)
				print_msg(philo, cnt, "died", 1);
			else
				print_msg(philo, cnt, "died", 0);
			pthread_mutex_unlock(&philo->share->end_mutex);
			pthread_mutex_unlock(&philo->share->check);
			return (cnt);
		}
		cnt++;
	}
	return (0);
}
