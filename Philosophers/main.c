/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:47:02 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/05/28 18:27:24 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_atoi(const char *str)
{
    long    n;

    n = 0;
    if (!*str || *str < '0' || *str > '9')
        ph_puterr("arg\n");
    if (*str == '0' && *(str + 1) != '\0')
        ph_puterr("arg\n");
    while (*str && *str >= '0' && *str <= '9')
    {
		n = n * 10 + *str - '0';
        str++;
    }
    if (*str != '\0')
		ph_puterr("arg\n");
	if (n > INT32_MAX || n < 0)
		ph_puterr("arg\n");
    return ((int)n);
}

static int	*ph_get_rule(int argc, char **argv)
{
	int	i;
	int *rule;

	if (argc != 5 && argc != 6)
		ph_puterr("arg\n");
	rule = (int *)malloc(sizeof(int) * 5);
	if (!rule)
		ph_puterr("malloc\n");
	i = -1;
	while (++i < argc - 1)
		rule[i] = ph_atoi(argv[i + 1]);
	if (argc == 5)
		rule[4] = -1;
	rule[1] *= 1000;
	rule[2] *= 1000;
	rule[3] *= 1000;
	return (rule);
}

int	main(int argc, char **argv)
{
	int				*rule;
	philo_t			*philos;

	rule = ph_get_rule(argc, argv);
	ph_philo_init(&philos, rule);
	ph_philo_start(&philos, rule);
	ph_philo_destroy(&philos, &rule);
}
