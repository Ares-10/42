/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:11:40 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/06 21:02:38 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	action_a_h_b_h(int *action, t_deque **stack_a, t_deque **stack_b)
{
	int	a_action;
	int	b_action;

	a_action = action[2];
	b_action = action[3];
	while (a_action && b_action)
	{
		a_action--;
		b_action--;
		ps_rr(stack_a, stack_b);
	}
	while (a_action--)
		ps_rotate(stack_a, 1);
	while (b_action--)
		ps_rotate(stack_b, 2);
	ps_push(stack_a, stack_b, 1);
}

static void	action_a_h_b_l(int *action, t_deque **stack_a, t_deque **stack_b)
{
	int	a_action;
	int	b_action;

	a_action = action[2];
	b_action = ps_lstsize(*stack_b) - action[3];
	while (a_action--)
		ps_rotate(stack_a, 1);
	while (b_action--)
		ps_rrotate(stack_b, 2);
	ps_push(stack_a, stack_b, 1);
}

static void	action_a_l_b_h(int *action, t_deque **stack_a, t_deque **stack_b)
{
	int	a_action;
	int	b_action;

	a_action = ps_lstsize(*stack_a) - action[2];
	b_action = action[3];
	while (a_action--)
		ps_rrotate(stack_a, 1);
	while (b_action--)
		ps_rotate(stack_b, 2);
	ps_push(stack_a, stack_b, 1);
	ps_push(stack_a, stack_b, 1);
}

static void	action_a_l_b_l(int *action, t_deque **stack_a, t_deque **stack_b)
{
	int	a_action;
	int	b_action;

	a_action = ps_lstsize(*stack_a) - action[2];
	b_action = ps_lstsize(*stack_b) - action[3];
	while (a_action && b_action)
	{
		a_action--;
		b_action--;
		ps_rrr(stack_a, stack_b);
	}
	while (a_action--)
		ps_rrotate(stack_a, 1);
	while (b_action--)
		ps_rrotate(stack_b, 2);
	ps_push(stack_a, stack_b, 1);
}

void	ps_sort(int *check_best, t_deque **stack_a, t_deque **stack_b)
{
	if (ps_lstsize(*stack_a) <= 5)
	{
		ps_short_sort(stack_a, stack_b);
		return ;
	}
	ps_lstmove_atob(stack_a, stack_b, 0);
	while (*stack_b)
	{
		ps_check_best(check_best, *stack_a, *stack_b);
		if (check_best[1] == A_H_B_H)
			action_a_h_b_h(check_best, stack_a, stack_b);
		else if (check_best[1] == A_H_B_L)
			action_a_h_b_l(check_best, stack_a, stack_b);
		else if (check_best[1] == A_L_B_H)
			action_a_l_b_h(check_best, stack_a, stack_b);
		else if (check_best[1] == A_L_B_L)
			action_a_l_b_l(check_best, stack_a, stack_b);
	}
	if ((*stack_a)->num > ps_lstlast(*stack_a)->num / 2)
		while ((*stack_a)->num > ps_lstlast(*stack_a)->num)
			ps_rotate(stack_a, 1);
	else
		while ((*stack_a)->num > ps_lstlast(*stack_a)->num)
			ps_rrotate(stack_a, 1);
}
