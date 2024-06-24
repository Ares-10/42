/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:25:09 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/06/24 20:16:00 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_philo_action(t_philo *philo)
{
	int	flag;

	pthread_mutex_lock(philo->right_fock);
	ph_putstat(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fock);
	ph_putstat(philo, "has taken a fork");
	ph_putstat(philo, "is eating");
	pthread_mutex_lock(&philo->mutex);
	philo->last_eat_time = ph_get_time();
	pthread_mutex_unlock(&philo->mutex);
	flag = ph_time_sleep(philo, philo->rule.time_to_eat);
	pthread_mutex_unlock(philo->left_fock);
	pthread_mutex_unlock(philo->right_fock);
	pthread_mutex_lock(&philo->mutex);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mutex);
	if (philo->eat_count == philo->rule.number_of_eats)
		flag = 0;
	return (flag);
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
		usleep(1000);
	}
	while (1)
	{
		if (!ph_philo_action(philo))
			return (NULL);
		ph_putstat(philo, "is sleeping");
		if (!ph_time_sleep(philo, rule.time_to_sleep))
			return (NULL);
		ph_putstat(philo, "is thinking");
	}
	return (NULL);
}

void	ph_philo_start(t_philo **philos, t_rule rule)
{
	int	i;

	i = -1;
	while (++i < rule.number_of_philos)
		if (pthread_create(&(*philos)[i].id, NULL, ph_philo_create, &(*philos)[i]))
			ph_puterr("pthread create failed\n");
	if (rule.number_of_philos != 1)
		ph_monitoring(*philos, rule);
	i = -1;
	while (++i < rule.number_of_philos)
		if (pthread_join((*philos)[i].id, NULL))
			ph_puterr("pthread join failed\n");
}
