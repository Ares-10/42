/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_best.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:55:30 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/07 23:11:55 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	check_action(int a_pos, int b_pos, int a_size, int b_size)
{
	int	minimum;
	int	action;

	action = A_H_B_H;
	minimum = max(a_pos, b_pos);
	if (max(a_size - a_pos, b_size - b_pos) + 1 < minimum)
	{
		action = A_L_B_L;
		minimum = max(a_size - a_pos, b_size - b_pos) + 1;
	}
	if (a_pos + b_size - b_pos + 1 < minimum)
	{
		action = A_H_B_L;
		minimum = a_pos + b_size - b_pos + 1;
	}
	if (a_size - a_pos + b_size + 1 < minimum)
	{
		action = A_L_B_H;
		minimum = a_size - a_pos + b_size + 1;
	}
	return (action);
}

static int	count_func(int a_pos, int b_pos, int a_size, int b_size)
{
	int	minimum;

	minimum = max(a_pos, b_pos);
	minimum = min(minimum, max(a_size - a_pos, b_size - b_pos) + 1);
	minimum = min(minimum, a_pos + b_size - b_pos + 1);
	minimum = min(minimum, a_size - a_pos + b_size + 1);
	return (minimum);
}

void	ps_check_best(int *check_best, t_deque *stack_a, t_deque *stack_b)
{
	int	a_pos;
	int	b_pos;
	int	a_size;
	int	b_size;

	a_size = ps_lstsize(stack_a);
	b_size = ps_lstsize(stack_b);
	b_pos = -1;
	check_best[0] = INT32_MAX;
	while (++b_pos < b_size)
	{
		a_pos = ps_getpushpos(ps_lstget(b_pos, stack_b), stack_a);
		if (count_func(a_pos, b_pos, a_size, b_size) < check_best[0])
		{
			check_best[0] = count_func(a_pos, b_pos, a_size, b_size);
			check_best[2] = a_pos;
			check_best[3] = b_pos;
		}
	}
	check_best[1] = check_action(check_best[2], check_best[3], a_size, b_size);
}
