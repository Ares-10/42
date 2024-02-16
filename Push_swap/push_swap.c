/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:54 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/16 17:08:03 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_puterr(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static long	ps_atol(const char *str)
{
	int		is_n;
	long	n;

	is_n = 0;
	n = 0;
	if (*str && (*str == '-' || *str == '+'))
		if (*str++ == '-')
			is_n++;
	if (!*str || !ft_isdigit(*str))
		ps_puterr();
	if (*str == '0' && *(str + 1) != '\0')
		ps_puterr();
	while (*str && ft_isdigit(*str))
	{
		n = n * 10 + *str - '0';
		str++;
	}
	if (*str != '\0')
		ps_puterr();
	if (is_n % 2 == 1)
		return (-n);
	return (n);
}

static void	ps_check_arg(int *check_num, int argc, char **argv)
{
	int		i;
	int		j;
	long	num;

	i = 0;
	while (++i < argc)
	{
		num = ps_atol(argv[i]);
		if (num < INT32_MIN || num > INT32_MAX)
			ps_puterr();
		check_num[i] = (int)num;
	}
	i = 0;
	while (++i < argc - 1)
	{
		j = i;
		while (++j < argc)
			if (check_num[j] == check_num[i])
				ps_puterr();
	}
}

static int	ps_split(char ***strs)
{
	int		count;

	(*strs)[1] = ft_strjoin("push_swap ", (*strs)[1]);
	if (!(*strs)[1])
		ps_puterr();
	*strs = ft_split((*strs)[1], ' ');
	if (!(*strs))
		ps_puterr();
	count = 0;
	while ((*strs)[count])
		count++;
	if (count < 2)
		exit(0);
	return (count);
}

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	int		*int_arr;

	if (argc < 2)
		exit(0);
	int_arr = (int *)malloc(sizeof(int) * argc);
	if (!int_arr)
		ps_puterr();
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		argc = ps_split(&argv);
	ps_check_arg(int_arr, argc, argv);
	ps_init(&stack_a, argc, int_arr);
	free(int_arr);
	if (ps_issorted(stack_a))
		exit(0);
	int_arr = (int *)malloc(sizeof(int) * 4);
	if (!int_arr)
		ps_puterr();
	ps_sort(int_arr, &stack_a, &stack_b);
	exit(0);
}
