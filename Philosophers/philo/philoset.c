/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 04:54:25 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/06/30 07:42:02 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork_mutex);
	pthread_mutex_lock(philo->lfork_mutex);
	*(philo->right_fork) = 1;
	*(philo->left_fork) = 1;
	ph_putstat(philo, "has taken a fork");
	ph_putstat(philo, "has taken a fork");
}

void	release_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork_mutex);
	pthread_mutex_unlock(philo->rfork_mutex);
	*(philo->right_fork) = 0;
	*(philo->left_fork) = 0;
}

void	ph_philo_set_finished_all(t_philo *philos, t_rule rule)
{
	int	i;

	i = -1;
	while (++i < rule.number_of_philos)
	{
		pthread_mutex_lock(&philos[i].mutex);
		(&philos[i])->is_alive = 0;
		pthread_mutex_unlock(&philos[i].mutex);
	}
}

void	ph_philo_destroy(t_philo **philos, int number_of_philos)
{
	int	i;

	i = -1;
	while (++i < number_of_philos)
	{
		pthread_mutex_destroy(&(*philos)[i].mutex);
		pthread_mutex_destroy(&(*philos)[i].eat_mutex);
		pthread_mutex_destroy((*philos)[i].rfork_mutex);
		free((*philos)[i].rfork_mutex);
		free((*philos)[i].left_fork);
	}
	free(*philos);
}

void	ph_philo_fork_init(t_philo **philos, int num_philos)
{
	int		i;

	i = -1;
	while (++i < num_philos)
	{
		(&(*philos)[i])->right_fork = (int *)malloc(sizeof(int));
		if (!(&(*philos)[i])->right_fork)
			ph_puterr("malloc failed\n");
		*((&(*philos)[i])->right_fork) = 0;
		(&(*philos)[i])->rfork_mutex = \
			(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!(&(*philos)[i])->rfork_mutex)
			ph_puterr("malloc failed\n");
		pthread_mutex_init((&(*philos)[i])->rfork_mutex, NULL);
		if (i + 1 < num_philos)
		{
			(*philos)[i + 1].left_fork = (&(*philos)[i])->right_fork;
			(*philos)[i + 1].lfork_mutex = (&(*philos)[i])->rfork_mutex;
		}
		else
		{
			(*philos)[0].left_fork = (&(*philos)[i])->right_fork;
			(*philos)[0].lfork_mutex = (&(*philos)[i])->rfork_mutex;
		}
	}
}
