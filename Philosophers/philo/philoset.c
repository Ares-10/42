/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 04:54:25 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/06/28 20:12:21 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork_mutex);
	pthread_mutex_lock(philo->left_fork_mutex);
	philo->right_fork = 1;
	philo->left_fork = 1;
	ph_putstat(philo, "has taken a fork");
	ph_putstat(philo, "has taken a fork");
}

void	release_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	philo->right_fork = 0;
	philo->left_fork = 0;
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
		pthread_mutex_destroy((*philos)[i].right_fork_mutex);
		free((*philos)[i].right_fork_mutex);
	}
	free(*philos);
}

void	ph_philo_init(t_philo **philos, t_rule rule)
{
	int		i;
	t_philo	*philo;

	*philos = (t_philo *)malloc(sizeof(t_philo) * rule.number_of_philos);
	if (!philos)
		ph_puterr("malloc failed\n");
	i = -1;
	while (++i < rule.number_of_philos)
	{
		philo = &(*philos)[i];
		philo->rule = rule;
		philo->eat_count = 0;
		philo->num = i + 1;
		philo->is_alive = 1;
		pthread_mutex_init(&philo->mutex, NULL);
		philo->right_fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo->right_fork_mutex, NULL);
		if (i + 1 < rule.number_of_philos)
			(*philos)[i + 1].left_fork_mutex = philo->right_fork_mutex;
		else
			(*philos)[0].left_fork_mutex = philo->right_fork_mutex;
		philo->last_eat_time = ph_get_time();
	}
}
