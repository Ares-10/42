/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:04:15 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/07/02 18:48:49 by hyungcho         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->rule->print_mutex);
	pthread_mutex_lock(&philo->mutex);
	if (philo->is_alive)
		printf("%lld %d %s\n", (ph_get_time() - philo->rule->start_time) \
			/ 1000, philo->num, msg);
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->rule->print_mutex);
}

void	ph_time_sleep(t_rule *rule, long long sleep_time)
{
	long long	start_time;
	long long	now;

	start_time = ph_get_time();
	while (1)
	{
		now = ph_get_time();
		if (now - start_time >= sleep_time)
			return ;
		pthread_mutex_lock(&rule->finished_mutex);
		if (rule->finished)
		{
			pthread_mutex_unlock(&rule->finished_mutex);
			return ;
		}
		pthread_mutex_unlock(&rule->finished_mutex);
		usleep(400);
	}
	return ;
}

static int	ph_philo_check_end(t_philo *philo, t_rule *rule)
{
	int	eat_count;

	if (!philo->is_alive)
		return (0);
	pthread_mutex_lock(&philo->eat_mutex);
	eat_count = philo->eat_count;
	if (ph_get_time() - philo->last_eat_time >= rule->time_to_die)
	{
		pthread_mutex_lock(&philo->mutex);
		philo->is_alive = 0;
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_lock(&rule->print_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->eat_mutex);
	if (eat_count == rule->number_of_eats)
	{
		pthread_mutex_lock(&philo->mutex);
		philo->is_alive = 0;
		pthread_mutex_unlock(&philo->mutex);
		return (2);
	}
	return (0);
}

void	ph_monitoring(t_philo *philos, t_rule *rule)
{
	int	finished_count;
	int	i;
	int	flag;

	finished_count = 0;
	while (finished_count != rule->number_of_philos)
	{
		i = -1;
		while (++i < rule->number_of_philos)
		{
			flag = ph_philo_check_end(&philos[i], rule);
			if (flag == 1)
			{
				ph_philo_set_finished_all(philos, rule);
				printf("%lld %d died\n", (ph_get_time() - rule->start_time) \
					/ 1000, i + 1);
				pthread_mutex_unlock(&rule->print_mutex);
				pthread_mutex_unlock(&(&philos[i])->eat_mutex);
				return ;
			}
			else if (flag == 2)
				finished_count++;
		}
		usleep(200);
	}
}
