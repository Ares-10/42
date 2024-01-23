/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:54 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/01/22 19:12:24 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_puterr(void)
{
	ft_putstr_fd("ERROR\n", 2);
	return (ERROR);
}

int	ps_check_arg(int argc, char **argv)
{
	int	check_num[argc];
	int	i;
	int n;

	i = 0;
	while (++i < argc)
		check_num[i++] = ERROR;
	i = 0;
	while (++i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n <= 0)
			return (ps_puterr());
		check_num[n] = SUCCESS;
	}
	i = 0;
	while (++ i < argc)
		if (check_num[i] == ERROR)
			return (ps_puterr());
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_deque	*stack_a;
	t_deque	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ps_check_arg(argc, argv) == ERROR || argc < 2)
		return (0);
	ps_init(&stack_a, &stack_b, argc, argv);
	ps_sort(argc - 1, &stack_a, &stack_b);
}
