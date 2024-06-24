/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:04:15 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/06/24 20:40:04 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ph_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	ph_putstat(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->mutex);
	if (philo->is_alive)
		printf("%lld %d %s\n", ph_get_time() / 1000, philo->num, msg);
	pthread_mutex_unlock(&philo->mutex);
}

int	ph_time_sleep(t_philo *philo, long long sleep_time)
{
	long long	start_time;
	long long	now;
	int			is_alive;

	start_time = ph_get_time();
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		is_alive = philo->is_alive;
		pthread_mutex_unlock(&philo->mutex);
		if (!is_alive)
			break ;
		now = ph_get_time();
		if (now - start_time >= sleep_time)
			return (1);
		usleep(200);
	}
	return (0);
}

static int	ph_philo_check_end(t_philo *philo, t_rule rule)
{
	int	flag;

	pthread_mutex_lock(&philo->mutex);
	if (!philo->is_alive)
	{
		pthread_mutex_unlock(&philo->mutex);
		return (0);
	}
	flag = 0;
	if (ph_get_time() - philo->last_eat_time >= rule.time_to_die)
	{
		printf("%lld %d died\n", ph_get_time() / 1000, philo->num);
		flag = 1;
	}
	else if (philo->eat_count == rule.number_of_eats)
	{
		philo->is_alive = 0;
		flag = 2;
	}
	pthread_mutex_unlock(&philo->mutex);
	return (flag);
}

void	ph_monitoring(t_philo *philos, t_rule rule)
{
	int	finished_count;
	int	i;
	int	flag;

	finished_count = 0;
	while (finished_count != rule.number_of_philos)
	{
		i = -1;
		while (++i < rule.number_of_philos)
		{
			flag = ph_philo_check_end(&philos[i], rule);
			if (flag == 1)
			{
				ph_philo_set_finished_all(philos, rule);
				return ;
			}
			else if (flag == 2)
				finished_count++;
		}
		usleep(200);
	}
}
