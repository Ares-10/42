/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:47:02 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/07/02 18:23:03 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_atoi(const char *str)
{
	long	n;

	n = 0;
	if (!*str || *str < '0' || *str > '9')
		ph_puterr("wrong argument\n");
	if (*str == '0' && *(str + 1) != '\0')
		ph_puterr("wrong argument\n");
	while (*str && *str >= '0' && *str <= '9')
	{
		n = n * 10 + *str - '0';
		str++;
	}
	if (*str != '\0')
		ph_puterr("wrong argument\n");
	if (n > INT32_MAX || n < 0)
		ph_puterr("wrong argument\n");
	return ((int)n);
}

static t_rule	*ph_get_rule(int argc, char **argv)
{
	t_rule	*rule;

	if (argc != 5 && argc != 6)
		ph_puterr("wrong argument\n");
	rule = (t_rule *)malloc(sizeof(t_rule));
	if (!rule)
		ph_puterr("malloc failed\n");
	rule->number_of_philos = ph_atoi(argv[1]);
	rule->time_to_die = ph_atoi(argv[2]) * 1000;
	rule->time_to_eat = ph_atoi(argv[3]) * 1000;
	rule->time_to_sleep = ph_atoi(argv[4]) * 1000;
	if (argc == 5)
		rule->number_of_eats = -1;
	else
		rule->number_of_eats = ph_atoi(argv[5]);
	if (rule->number_of_philos <= 0
		|| rule->time_to_die <= 0
		|| rule->time_to_eat <= 0
		|| rule->time_to_sleep <= 0
		|| (argc == 6 && rule->number_of_eats <= 0))
		ph_puterr("wrong argument\n");
	rule->finished = 0;
	pthread_mutex_init(&rule->print_mutex, NULL);
	return (rule);
}

static void	free_rule(t_rule **rule)
{
	pthread_mutex_destroy(&(*rule)->print_mutex);
	free(*rule);
}

static void	ph_philo_init(t_philo **philos, t_rule *rule)
{
	int		i;
	t_philo	*philo;

	*philos = (t_philo *)malloc(sizeof(t_philo) * rule->number_of_philos);
	if (!philos)
		ph_puterr("malloc failed\n");
	ph_philo_fork_init(philos, rule->number_of_philos);
	i = -1;
	while (++i < rule->number_of_philos)
	{
		philo = &(*philos)[i];
		philo->rule = rule;
		philo->eat_count = 0;
		philo->num = i + 1;
		philo->is_alive = 1;
		pthread_mutex_init(&philo->mutex, NULL);
		pthread_mutex_init(&philo->eat_mutex, NULL);
		philo->last_eat_time = ph_get_time();
	}
}

int	main(int argc, char **argv)
{
	t_rule	*rule;
	t_philo	*philos;

	rule = ph_get_rule(argc, argv);
	ph_philo_init(&philos, rule);
	ph_philo_start(&philos, rule);
	ph_philo_destroy(&philos, rule->number_of_philos);
	free_rule(&rule);
}
