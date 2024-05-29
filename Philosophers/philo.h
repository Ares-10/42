/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:52:56 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/05/28 21:40:32 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct philo_s
{
	pthread_t		id;
	int				num;
	int				eat_count;
	int				*rule;
	long			last_eat_time;
	int				is_alive;
	pthread_mutex_t	*left_fock;
	pthread_mutex_t	*right_fock;
}	philo_t;


void	ph_puterr(char *msg);

long	ph_get_time(void);
void	ph_putstat(philo_t *philo, char *msg);
void	ph_monitoring(philo_t **philos, int *rule);

void	ph_philo_init(philo_t **philos, int *rule);
void	ph_philo_start(philo_t **philos, int *rule);
void	ph_philo_destroy(philo_t **philos, int **rule);

#endif
