/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:54 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/05 21:57:34 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_puterr(void)
{
	ft_putstr_fd("ERROR\n", 2);
	return (ERROR);
}

static long	ps_atol(const char *str)
{
	int		is_n;
	long	n;

	is_n = 0;
	n = 0;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (*str && (*str == '-' || *str == '+'))
		if (*str++ == '-')
			is_n++;
	if (*str && *str == '0' && *(str + 1))
		return ((long)INT32_MAX + 1);
	while (*str && ft_isdigit(*str))
	{
		n = n * 10 + *str - '0';
		str++;
	}
	if (n == 0 || *str)
		return ((long)INT32_MAX + 1);
	if (is_n % 2 == 1)
		return (-n);
	return (n);
}

static int	ps_check_arg(int *check_num, int argc, char **argv)
{
	int		i;
	int		j;
	long	num;

	i = 0;
	while (++i < argc)
	{
		num = ps_atol(argv[i]);
		if (num < INT32_MIN || num > INT32_MAX)
			return (ps_puterr());
		check_num[i] = (int)num;
	}
	i = 0;
	while (++i < argc - 1)
	{
		j = i;
		while (++j < argc)
			if (check_num[j] == check_num[i])
				return (ps_puterr());
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_deque	*stack_a;
	t_deque	*stack_b;
	int		*num_arr;

	num_arr = (int *)malloc(sizeof(int) * argc);
	if (!num_arr)
		return (ps_puterr());
	stack_a = NULL;
	stack_b = NULL;
	if (ps_check_arg(num_arr, argc, argv) == ERROR || argc < 2)
	{
		free(num_arr);
		return (0);
	}
	ps_init(&stack_a, &stack_b, argc, num_arr);
	free(num_arr);
	if (ps_issorted(stack_a))
		return (0);
	num_arr = (int *)malloc(sizeof(int) * 4);
	if (!num_arr)
		return (ps_puterr());
	ps_sort(num_arr, &stack_a, &stack_b);
	free(num_arr);
}
