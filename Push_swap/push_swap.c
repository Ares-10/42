/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:54 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/01/08 18:47:52 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ps_puterr(void)
{
	ft_putstr_fd("ERROR\n", 2);
	return (ERROR);
}

int	ft_ps_check_arg(int argc, char **argv)
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
			return (ft_ps_puterr());
		check_num[n] = SUCCESS;
	}
	i = 0;
	while (++ i < argc)
		if (check_num[i] == ERROR)
			return (ft_ps_puterr());
	return (SUCCESS);
}
#include <stdio.h>

void print_stack(t_list *sa, t_list *sb, int a, int b)
{
	t_list *stack_a = sa;
	t_list *stack_b = sb;
	
	printf("\nstack_a\n");
	while (stack_a)
	{
		printf("%d\n", *(int *)(stack_a->content));
		stack_a = stack_a->next;
	}
	
	printf("\nstack_b\n");
	while (stack_b)
	{
		printf("%d\n", *(int *)(stack_b->content));
		stack_b = stack_b->next;
	}
	printf("\n\n");
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ft_ps_check_arg(argc, argv) == ERROR || argc < 2)
		return (0);


	*stack_b = NULL;
	*stack_b = NULL;
	ft_ps_init(stack_a, argc, argv);
	print_stack(*stack_a, *stack_b, 6, 0);

	ft_ps_push(stack_b, stack_a, 2);

	print_stack(*stack_a, *stack_b, 5, 1);
	ft_ps_push(stack_b, stack_a, 2);
	
	print_stack(*stack_a, *stack_b, 4, 2);
	ft_ps_rotate(stack_a, 1);

	print_stack(*stack_a, *stack_b, 4, 2);
	ft_ps_swap(stack_a, 1);

	print_stack(*stack_a, *stack_b, 4, 2);
	ft_ps_rrotate(stack_a, 1);

	print_stack(*stack_a, *stack_b, 4, 2);
}
