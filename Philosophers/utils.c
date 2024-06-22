/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:04:15 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/06/23 03:22:15 by johyeongeun      ###   ########.fr       */
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
	if (!philo->is_alive)
		return ;
	printf("%lld %d %s\n", ph_get_time() / 1000, philo->num, msg);
}

int	ph_time_sleep(t_philo *philo, long long sleep_time)
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

void	ph_monitoring(t_philo *philos, t_rule rule)
{
	int			finished_count;
	int			i;

	finished_count = 0;
	while (finished_count != rule.number_of_philos)
	{
		i = -1;
		while (++i < rule.number_of_philos)
		{
			if (!philos[i].is_alive)
				continue ;
			if (ph_get_time() - philos[i].last_eat_time >= rule.time_to_die)
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
		usleep(500);
	}
}
