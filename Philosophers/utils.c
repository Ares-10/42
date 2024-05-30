/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:04:15 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/05/30 19:49:34 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ph_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	ph_putstat(philo_t *philo, char *msg)
{
	if (!philo->is_alive)
		return ;
	printf("%lld %d %s\n", ph_get_time() / 1000, philo->num, msg);
}

int	ph_time_sleep(philo_t *philo, long long sleep_time)
{
	long long	start_time;
	long long	now;

	start_time = ph_get_time();
	while (philo->is_alive)
	{
		now = ph_get_time();
		if (now - start_time >= sleep_time)
			return (1);
		usleep(10);
	}
	return (0);
}

void	ph_monitoring(philo_t *philos, rule_t rule)
{
	int			finished_count;
	int			i;
	long long	now;

	if (rule.number_of_philos == 1)
		return ;
	finished_count = 0;
	while (finished_count != rule.number_of_philos)
	{
		i = -1;
		while (++i < rule.number_of_philos)
		{
			if (philos[i].is_alive)
			{
				now = ph_get_time();			
				if (now - philos[i].last_eat_time >= rule.time_to_die)
				{
					ph_putstat(&philos[i], "died");
					philos[i].is_alive = 0;
					finished_count++;
				}
				if (philos[i].eat_count == rule.number_of_eats)
				{
					philos[i].is_alive = 0;
					finished_count++;
				}
			}
		}
		usleep(500);
	}
}
