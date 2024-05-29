/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:25:09 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/05/28 21:39:43 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_philo_action(philo_t *philo)
{
	pthread_mutex_lock(philo->right_fock);
	ph_putstat(philo, "has taken a fork");
	if (philo->rule[0] == 1)
	{
		usleep(philo->rule[2]);
		ph_putstat(philo, "died");
		pthread_mutex_unlock(philo->right_fock);
		philo->is_alive = 0;
		return;
	}
	pthread_mutex_lock(philo->left_fock);
	ph_putstat(philo, "has taken a fork");
	ph_putstat(philo, "is eating");
	usleep(philo->rule[2]);
	philo->eat_count++;
	philo->last_eat_time = ph_get_time();
	pthread_mutex_unlock(philo->left_fock);
	pthread_mutex_unlock(philo->right_fock);
}

static void	*ph_philo_create(void *p)
{
	philo_t	*philo;

	philo = (philo_t *)p;
	if (philo->rule[0] == 1)
	{
		ph_philo_action(philo);
		return (NULL);
	}
	if (philo->num % 2 == 1 && philo->rule[0] != 1)
	{
		ph_putstat(philo, "is thinking");
		usleep(200);
	}
	while (philo->is_alive)
	{
		ph_philo_action(philo);
		if (philo->eat_count == philo->rule[4])
			break;
		ph_putstat(philo, "is sleeping");
		usleep(philo->rule[3]);
		ph_putstat(philo, "is thinking");
	}
	return (NULL);
}

void	ph_philo_start(philo_t **philos, int *rule)
{
	int	i;

	i = -1;
	while (++i < rule[0])
		if (pthread_create(&(*philos)[i].id, NULL, ph_philo_create, &(*philos)[i]))
			ph_puterr("pthread_create\n");
	ph_monitoring(philos, rule);
	i = -1;
	while (++i < rule[0])
		pthread_join((*philos)[i].id, NULL);
}

void	ph_philo_destroy(philo_t **philos, int **rule)
{
	int i;

	i = -1;
	while (++i < (*rule)[0])
	{
		pthread_mutex_destroy((*philos)[i].right_fock);
		free((*philos)[i].right_fock);
	}
	free(*philos);
	free(*rule);
}

void	ph_philo_init(philo_t **philos, int *rule)
{
	int	i;

	*philos = (philo_t *)malloc(sizeof(philo_t) * rule[0]);
	if (!philos)
		ph_puterr("malloc\n");
	i = -1;
	while (++i < rule[0])
	{
		(*philos)[i].rule = rule;
		(*philos)[i].eat_count = 0;
		(*philos)[i].num = i + 1;
		(*philos)[i].is_alive = 1;
		(*philos)[i].right_fock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init((*philos)[i].right_fock, NULL);
		if (i + 1 < rule[0])
			(*philos)[i + 1].left_fock = (*philos)[i].right_fock;
		else
			(*philos)[0].left_fock = (*philos)[i].right_fock;
		(*philos)[i].last_eat_time = ph_get_time();
	}
}
