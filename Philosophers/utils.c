/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:04:15 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/05/28 21:39:21 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ph_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ph_putstat(philo_t *philo, char *msg)
{
	if (!philo->is_alive)
		return;
	printf("%ld %d %s\n", ph_get_time(), philo->num, msg);
}

void	ph_monitoring(philo_t **philos, int *rule)
{
	int	finished_count;
	int	i;

	if (rule[0] == 1)
		return ;
	finished_count = 0;
	while (finished_count != rule[0])
	{
		i = -1;
		while (++i < rule[0])
		{
			if ((*philos)[i].is_alive)
			{
				if (ph_get_time() - (*philos)[i].last_eat_time >= rule[2])
				{
					ph_putstat(&(*philos)[i], "died");
					(*philos)[i].is_alive = 0;
					finished_count++;
				}
				if ((*philos)[i].eat_count == rule[4])
				{
					finished_count++;
					(*philos)[i].is_alive = 0;
				}
			}
		}
		usleep(500);
	}
}
