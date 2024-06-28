/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:25:09 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/06/28 20:12:13 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_philo_action(t_philo *philo)
{
	int	flag;

	pick_fork(philo);
	ph_putstat(philo, "is eating");
	pthread_mutex_lock(&philo->mutex);
	philo->last_eat_time = ph_get_time();
	flag = philo->is_alive;
	pthread_mutex_unlock(&philo->mutex);
	ph_time_sleep(philo->rule.time_to_eat);
	release_fork(philo);
	pthread_mutex_lock(&philo->mutex);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mutex);
	if (philo->eat_count == philo->rule.number_of_eats)
		flag = 0;
	return (flag);
}

static void	*ph_one_philo_action(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork_mutex);
	ph_putstat(philo, "has taken a fork");
	usleep(philo->rule.time_to_die);
	ph_putstat(philo, "died");
	pthread_mutex_unlock(philo->right_fork_mutex);
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
		usleep(5000);
	}
	pthread_mutex_lock(&philo->mutex);
	while (philo->is_alive)
	{
		pthread_mutex_unlock(&philo->mutex);
		if (!ph_philo_action(philo))
			break ;
		ph_putstat(philo, "is sleeping");
		ph_time_sleep(rule.time_to_sleep);
		ph_putstat(philo, "is thinking");
	}
	pthread_mutex_unlock(&philo->mutex);
	return (NULL);
}

void	ph_philo_start(t_philo **p, t_rule rule)
{
	int		i;
	t_philo	*philos;

	philos = *p;
	i = -1;
	while (++i < rule.number_of_philos)
		if (pthread_create(&philos[i].id, NULL, ph_philo_create, &philos[i]))
			ph_puterr("pthread create failed\n");
	if (rule.number_of_philos != 1)
		ph_monitoring(philos, rule);
	i = -1;
	while (++i < rule.number_of_philos)
		if (pthread_join(philos[i].id, NULL))
			ph_puterr("pthread join failed\n");
}
