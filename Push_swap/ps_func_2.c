/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_func_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:24:09 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/09 18:47:03 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_utils.h"

void	ps_rr(t_deque **stack_a, t_deque **stack_b)
{
	ps_rotate(stack_a, 0);
	ps_rotate(stack_b, 0);
	ft_putstr_fd("rr\n", 1);
}

void	ps_rrr(t_deque **stack_a, t_deque **stack_b)
{
	ps_rrotate(stack_a, 0);
	ps_rrotate(stack_b, 0);
	ft_putstr_fd("rrr\n", 1);
}

int	ps_getpushpos(int pull_num, t_deque *lst)
{
	int	push_pos;

	if (ps_lstsize(lst) < 2
		|| (pull_num < lst->num && pull_num > ps_lstlast(lst)->num)
		|| (lst->num < ps_lstlast(lst)->num
			&& (pull_num < lst->num || pull_num > ps_lstlast(lst)->num)))
		return (0);
	push_pos = 0;
	while (lst->next)
	{
		lst = lst->next;
		push_pos++;
		if (pull_num < lst->num && pull_num > lst->prev->num)
			break ;
		if (lst->num < lst->prev->num
			&& (pull_num < lst->num || pull_num > lst->prev->num))
			break ;
	}
	return (push_pos);
}

void	ps_lstmove_atob(t_deque **stack_a, t_deque **stack_b, int n)
{
	int	a_size;
	int	m;

	a_size = ps_lstsize(*stack_a);
	m = a_size / 3;
	if (a_size <= 5)
	{
		ps_short_sort(stack_a, stack_b);
		return ;
	}
	while (a_size--)
	{
		if ((*stack_a)->num > n + m * 2)
			ps_rotate(stack_a, 1);
		else if ((*stack_a)->num > n + m)
			ps_push(stack_b, stack_a, 2);
		else
		{
			ps_push(stack_b, stack_a, 2);
			ps_rotate(stack_b, 2);
		}
	}
	ps_lstmove_atob(stack_a, stack_b, n + m * 2);
}

int	ps_issorted(t_deque *stack)
{
	int	prev_num;

	prev_num = stack->num;
	stack = stack->next;
	while (stack)
	{
		if (prev_num > stack->num)
			return (0);
		prev_num = stack->num;
		stack = stack->next;
	}
	return (1);
}
