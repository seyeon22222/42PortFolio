/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:43:55 by seykim            #+#    #+#             */
/*   Updated: 2023/09/25 18:13:41 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	info_init(char **argv, t_info *info)
{
	info->philo_nums = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (info->philo_nums <= 0 || info->time_to_die <= 0 \
	|| info->time_to_eat <= 0 || info->time_to_sleep <= 0)
	{
		printf("Can't set argv : error");
		return (1);
	}
	if (argv[5])
	{
		info->must_eat_count = ft_atoi(argv[5]);
		if (info->must_eat_count <= 0)
		{
			printf("Can't set argv : error");
			return (1);
		}
	}
	else
		info->must_eat_count = 0;
	return (0);
}

int	share_init(t_share *share, t_info *info)
{
	int	cnt;

	share->start = get_time();
	share->dead_flag = 0;
	share->flag = 0;
	share->finish = 0;
	share->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
	info->philo_nums);
	if (!share->fork)
		return (1);
	if (pthread_mutex_init(&share->print_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&share->end_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&share->check, NULL))
		return (1);
	cnt = 0;
	while (cnt < info->philo_nums)
	{
		if (pthread_mutex_init(&share->fork[cnt], NULL))
			return (1);
		cnt++;
	}
	return (0);
}

int	philo_init(t_info *info, t_share *share, t_philo **philo)
{
	int	cnt;

	*philo = (t_philo *)malloc(info->philo_nums * sizeof(t_philo));
	if (!(*philo))
		return (1);
	cnt = 0;
	while (cnt < info->philo_nums)
	{
		(*philo)[cnt].self_num = cnt;
		(*philo)[cnt].left_fork = cnt;
		(*philo)[cnt].right_fork = (cnt + 1) % info->philo_nums;
		(*philo)[cnt].eat_cnt = 0;
		(*philo)[cnt].last_eat = get_time();
		(*philo)[cnt].share = share;
		(*philo)[cnt].info = *info;
		cnt++;
	}
	return (0);
}
