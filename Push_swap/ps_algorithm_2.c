/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:12:48 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/06 19:03:06 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_sort_3(t_deque **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->num;
	b = (*stack_a)->next->num;
	c = (*stack_a)->next->next->num;
	if (c < a && a < b)
		ps_rrotate(stack_a, 1);
	else if (b < a && a < c)
		ps_swap(stack_a, 1);
	else if (b < c && c < a)
		ps_rotate(stack_a, 1);
	else if (c < b && b < a)
	{
		ps_rotate(stack_a, 1);
		ps_swap(stack_a, 1);
	}
	else if (a < c && c < b)
	{
		ps_rrotate(stack_a, 1);
		ps_swap(stack_a, 1);
	}
}

static void	ps_sort_4(t_deque **stack_a, t_deque **stack_b)
{
	while ((*stack_a)->num != 0)
		ps_rotate(stack_a, 1);
	ps_push(stack_b, stack_a, 2);
	ps_sort_3(stack_a);
	ps_push(stack_a, stack_b, 1);
	return ;
}

static void	ps_sort_5(t_deque **stack_a, t_deque **stack_b)
{
	int	push_pos;

	ps_push(stack_b, stack_a, 2);
	ps_push(stack_b, stack_a, 2);
	ps_sort_3(stack_a);
	push_pos = ps_getpushpos((*stack_b)->num, *stack_a);
	ps_push(stack_a, stack_b, 1);
	if (push_pos == 2)
		ps_rrotate(stack_a, 1);
	if (push_pos == 1 || push_pos == 2)
		ps_swap(stack_a, 1);
	push_pos = ps_getpushpos((*stack_b)->num, *stack_a);
	if (push_pos == 2)
		ps_rotate(stack_a, 1);
	if (push_pos == 3)
		ps_rrotate(stack_a, 1);
	ps_push(stack_a, stack_b, 1);
	if (push_pos == 1 || push_pos == 2)
		ps_swap(stack_a, 1);
	if ((*stack_a)->num > 2)
		while ((*stack_a)->num > ps_lstlast(*stack_a)->num)
			ps_rotate(stack_a, 1);
	else
		while ((*stack_a)->num > ps_lstlast(*stack_a)->num)
			ps_rrotate(stack_a, 1);
}

void	ps_short_sort(t_deque **stack_a, t_deque **stack_b)
{
	if (ps_lstsize(*stack_a) == 2)
		ps_swap(stack_a, 1);
	else if (ps_lstsize(*stack_a) == 3)
		ps_sort_3(stack_a);
	else if (ps_lstsize(*stack_a) == 4)
		ps_sort_4(stack_a, stack_b);
	else if (ps_lstsize(*stack_a) == 5)
		ps_sort_5(stack_a, stack_b);
}
