/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:25:09 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/06/23 03:31:17 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_philo_action(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fock);
	ph_putstat(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fock);
	ph_putstat(philo, "has taken a fork");
	ph_putstat(philo, "is eating");
	philo->last_eat_time = ph_get_time();
	philo->eat_count++;
	if (!ph_time_sleep(philo, philo->rule.time_to_eat))
	{
		pthread_mutex_unlock(philo->left_fock);
		pthread_mutex_unlock(philo->right_fock);
		return (0);
	}
	pthread_mutex_unlock(philo->left_fock);
	pthread_mutex_unlock(philo->right_fock);
	return (1);
}

static void	*ph_one_philo_action(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fock);
	ph_putstat(philo, "has taken a fork");
	usleep(philo->rule.time_to_die);
	ph_putstat(philo, "died");
	pthread_mutex_unlock(philo->right_fock);
	philo->is_alive = 0;
	return (NULL);
}

static void	*ph_philo_create(void *p)
{
	t_philo	*philo;
	t_rule	rule;

	philo = (t_philo *)p;
	rule = philo->rule;
	if (rule.number_of_philos == 1)
		return (ph_one_philo_action(philo));
	if (philo->num % 2 == 1)
	{
		ph_putstat(philo, "is thinking");
		usleep(200);
	}
	while (philo->is_alive)
	{
		if (!ph_philo_action(philo))
			return (NULL);
		if (philo->eat_count == rule.number_of_eats)
			return (NULL);
		ph_putstat(philo, "is sleeping");
		if (!ph_time_sleep(philo, rule.time_to_sleep))
			return (NULL);
		ph_putstat(philo, "is thinking");
	}
	return (NULL);
}

void	ph_philo_start(t_philo *philos, t_rule rule)
{
	int	i;

	i = -1;
	while (++i < rule.number_of_philos)
		if (pthread_create(&philos[i].id, NULL, ph_philo_create, &(philos[i])))
			ph_puterr("pthread create failed\n");
	if (rule.number_of_philos != 1)
		ph_monitoring(philos, rule);
	i = -1;
	while (++i < rule.number_of_philos)
		if (pthread_join(philos[i].id, NULL))
			ph_puterr("pthread join failed\n");
}

void	ph_philo_destroy(t_philo **philos, int number_of_philos)
{
	int	i;

	i = -1;
	while (++i < number_of_philos)
	{
		pthread_mutex_destroy((*philos)[i].right_fock);
		free((*philos)[i].right_fock);
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
		philo->right_fock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo->right_fock, NULL);
		if (i + 1 < rule.number_of_philos)
			(*philos)[i + 1].left_fock = philo->right_fock;
		else
			(*philos)[0].left_fock = philo->right_fock;
		philo->last_eat_time = ph_get_time();
	}
}
