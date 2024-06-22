/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:52:56 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/06/23 03:38:10 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_rule
{
	int			number_of_philos;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			number_of_eats;
}	t_rule;

typedef struct s_philo
{
	pthread_t		id;
	int				num;
	int				eat_count;
	t_rule			rule;
	long long		last_eat_time;
	int				is_alive;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*left_fock;
	pthread_mutex_t	*right_fock;
}	t_philo;

void		ph_puterr(char *msg);

long long	ph_get_time(void);
void		ph_putstat(t_philo *philo, char *msg);
int			ph_time_sleep(t_philo *philo, long long sleep_time);
void		ph_monitoring(t_philo *philos, t_rule rule);

void		ph_philo_init(t_philo **philos, t_rule rule);
void		ph_philo_start(t_philo *philos, t_rule rule);
void		ph_philo_destroy(t_philo **philos, int number_of_philos);

#endif
