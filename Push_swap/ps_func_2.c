/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_func_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:24:09 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/17 00:57:31 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_utils.h"

void	ps_rr(t_dlist **stack_a, t_dlist **stack_b)
{
	ps_rotate(stack_a, 0);
	ps_rotate(stack_b, 0);
	ft_putstr_fd("rr\n", 1);
}

void	ps_rrr(t_dlist **stack_a, t_dlist **stack_b)
{
	ps_reverse_rotate(stack_a, 0);
	ps_reverse_rotate(stack_b, 0);
	ft_putstr_fd("rrr\n", 1);
}

int	ps_getpushpos(int pull_num, t_dlist *lst)
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

void	ps_lstmove_atob(t_dlist **stack_a, t_dlist **stack_b, int n)
{
	int	a_size;
	int	pivot1;
	int	pivot2;

	a_size = ps_lstsize(*stack_a);
	pivot1 = n + a_size / 3;
	pivot2 = n + a_size / 3 * 2;
	if (a_size <= 5)
	{
		ps_short_sort(stack_a, stack_b);
		return ;
	}
	while (a_size--)
	{
		if ((*stack_a)->num <= pivot1)
		{
			ps_push(stack_b, stack_a, 2);
			ps_rotate(stack_b, 2);
		}
		else if ((*stack_a)->num <= pivot2)
			ps_push(stack_b, stack_a, 2);
		else
			ps_rotate(stack_a, 1);
	}
	ps_lstmove_atob(stack_a, stack_b, pivot2);
}

int	ps_issorted(t_dlist *stack)
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
