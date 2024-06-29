/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:47:02 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/06/30 06:51:02 by johyeongeun      ###   ########.fr       */
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

static t_rule	ph_get_rule(int argc, char **argv)
{
	t_rule	rule;

	if (argc != 5 && argc != 6)
		ph_puterr("wrong argument\n");
	rule.number_of_philos = ph_atoi(argv[1]);
	rule.time_to_die = ph_atoi(argv[2]) * 1000;
	rule.time_to_eat = ph_atoi(argv[3]) * 1000;
	rule.time_to_sleep = ph_atoi(argv[4]) * 1000;
	if (argc == 5)
		rule.number_of_eats = -1;
	else
		rule.number_of_eats = ph_atoi(argv[5]);
	if (rule.number_of_philos <= 0
		|| rule.time_to_die <= 0
		|| rule.time_to_eat <= 0
		|| rule.time_to_sleep <= 0
		|| (argc == 6 && rule.number_of_eats <= 0))
		ph_puterr("wrong argument\n");
	rule.start_time = ph_get_time();
	return (rule);
}

int	main(int argc, char **argv)
{
	t_rule	rule;
	t_philo	*philos;

	rule = ph_get_rule(argc, argv);
	ph_philo_init(&philos, rule);
	ph_philo_start(&philos, rule);
	ph_philo_destroy(&philos, rule.number_of_philos);
}
