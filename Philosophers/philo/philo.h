/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:52:56 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/07/02 18:48:15 by hyungcho         ###   ########.fr       */
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
	int				number_of_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				number_of_eats;
	long long		start_time;
	int				finished;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	finished_mutex;
}	t_rule;

typedef struct s_philo
{
	pthread_t		id;
	int				num;
	int				eat_count;
	t_rule			*rule;
	long long		last_eat_time;
	int				is_alive;
	int				*left_fork;
	int				*right_fork;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	*lfork_mutex;
	pthread_mutex_t	*rfork_mutex;
}	t_philo;

void		ph_puterr(char *msg);

long long	ph_get_time(void);
void		ph_putstat(t_philo *philo, char *msg);
void		ph_time_sleep(t_rule *rule, long long sleep_time);
void		ph_monitoring(t_philo *philos, t_rule *rule);

void		pick_fork(t_philo *philo);
void		release_fork(t_philo *philo);

void		ph_philo_fork_init(t_philo **philos, int num_philos);
void		ph_philo_start(t_philo **philos, t_rule *rule);
void		ph_philo_destroy(t_philo **philos, int number_of_philos);
void		ph_philo_set_finished_all(t_philo *philos, t_rule *rule);

#endif
