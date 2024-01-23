/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:11:40 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/01/22 18:50:33 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_move_atob(int size, t_deque **stack_a, t_deque **stack_b)
{
	int	n;

	n = 1;
	while (size--)
	{
		if ((*stack_a)->num == n)
		{
			n++;
			ps_rotate(stack_a, 1);
		}
		// else if ((*stack_a)->num < size / 3 * 2)
		// {
		// 	ps_push(stack_b, stack_a, 2);
		// 	ps_rotate(stack_b, 2);
		// }
		else
			ps_push(stack_b, stack_a, 2);
	}
}

static int	ps_count_func(int b_pos, t_deque *stack_a, t_deque *stack_b)
{
	int		a_pos;
	int		b_num;
	int		i;
	int		min;
	t_deque	*ptr;
	
	i = -1;
	ptr = stack_b;
	while (++i < b_pos)
		ptr = ptr->next;
	b_num = ptr->num;
	a_pos = 0;
	ptr = stack_a;
	while (ptr->num < b_num)
	{
		a_pos++;
		if (!ptr->next || ptr->next->num > b_num)
			break;
		ptr = ptr->next;
	}
	min = MIN(MAX(a_pos, b_pos), MAX(ps_lstsize(stack_a) - a_pos + 1, ps_lstsize(stack_b) - b_pos + 1));
	return (min);
}

static int	ps_check_best(t_deque **stack_a, t_deque **stack_b)
{
	int		i;
	int		check;
	int		best_count;
	int		best_idx;
	int		b_size;

	best_count = INT32_MAX;
	i = -1;
	b_size = ps_lstsize(*stack_b);
	while (++i < b_size)
	{
		check = ps_count_func(i, *stack_a, *stack_b);
		if (check < best_count)
		{
			best_count = check;
			best_idx = i;
		}
	}
	return (best_idx);
}

static void	ps_push_best(int pull_idx, t_deque **stack_a, t_deque **stack_b)
{
	int	push_idx;

	push_idx = 0;
	while (push_idx < ps_lstsize(*stack_a) && ps_lstget(push_idx, *stack_a) < ps_lstget(pull_idx, *stack_b))
		push_idx++;
	if (push_idx == ps_lstsize(*stack_a))
		while ((*stack_a)->num != 1)
			ps_rotate(stack_a, 1);
	while (pull_idx && push_idx)
	{
		ps_rr(stack_a, stack_b);
		pull_idx--;
		push_idx--;
	}
	while (pull_idx--)
		ps_rotate(stack_b, 2);
	while (push_idx--)
		ps_rotate(stack_a, 1);
	ps_push(stack_a, stack_b, 1);
}

void	ps_sort(int size, t_deque **stack_a, t_deque **stack_b)
{
	int	pull_idx;

	ps_move_atob(size, stack_a, stack_b);
	while (*stack_b)
	{
		pull_idx = ps_check_best(stack_a, stack_b);
		ps_push_best(pull_idx, stack_a, stack_b);
	}
	while ((*stack_a)->num != 1)
		ps_rotate(stack_a, 1);
}
