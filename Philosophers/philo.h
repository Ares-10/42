/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:52:56 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/05/30 18:48:34 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct rule_s
{
	int			number_of_philos;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			number_of_eats;
}	rule_t;

typedef struct philo_s
{
	pthread_t		id;
	int				num;
	int				eat_count;
	rule_t			rule;
	long long		last_eat_time;
	int				is_alive;
	pthread_mutex_t	*left_fock;
	pthread_mutex_t	*right_fock;
}	philo_t;


void		ph_puterr(char *msg);

long long	ph_get_time(void);
void		ph_putstat(philo_t *philo, char *msg);
int			ph_time_sleep(philo_t *philo, long long sleep_time);
void		ph_monitoring(philo_t *philos, rule_t rule);

void		ph_philo_init(philo_t **philos, rule_t rule);
void		ph_philo_start(philo_t *philos, rule_t rule);
void		ph_philo_destroy(philo_t **philos, int number_of_philos);

#endif
