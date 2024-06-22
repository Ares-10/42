/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 04:54:25 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/06/23 04:54:40 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_philo_destroy(t_philo **philos, int number_of_philos)
{
	int	i;

	i = -1;
	while (++i < number_of_philos)
	{
		pthread_mutex_destroy(&(*philos)[i].mutex);
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
		pthread_mutex_init(&philo->mutex, NULL);
		philo->right_fock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo->right_fock, NULL);
		if (i + 1 < rule.number_of_philos)
			(*philos)[i + 1].left_fock = philo->right_fock;
		else
			(*philos)[0].left_fock = philo->right_fock;
		philo->last_eat_time = ph_get_time();
	}
}
