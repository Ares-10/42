/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 04:54:25 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/06/28 15:47:49 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		pthread_mutex_destroy((*philos)[i].right_fork);
		free((*philos)[i].right_fork);
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
		pthread_mutex_init(&philo->eat_mutex, NULL);
		philo->right_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo->right_fork, NULL);
		if (i + 1 < rule.number_of_philos)
			(*philos)[i + 1].left_fork = philo->right_fork;
		else
			(*philos)[0].left_fork = philo->right_fork;
		philo->last_eat_time = ph_get_time();
	}
}
