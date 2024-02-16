/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_func_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:00:55 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/16 17:07:45 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_utils.h"

void	ps_swap(t_dlist **stack, int flag)
{
	t_dlist	*temp_ptr1;
	t_dlist	*temp_ptr2;

	if (!(*stack) || !((*stack)->next))
		return ;
	if (ps_lstsize(*stack) > 2)
	{
		temp_ptr1 = *stack;
		temp_ptr2 = (*stack)->next;
		*stack = (*stack)->next->next;
		ps_lstadd_front(stack, temp_ptr1);
		ps_lstadd_front(stack, temp_ptr2);
	}
	else
	{
		temp_ptr1 = *stack;
		(*stack)->next->next = *stack;
		(*stack)->next->prev = NULL;
		(*stack)->next->next->prev = (*stack)->next;
		(*stack)->next->next->next = NULL;
	}
	if (flag == 1)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	ps_push(t_dlist **stack_1, t_dlist **stack_2, int flag)
{
	t_dlist	*temp_ptr;

	if (!(*stack_2))
		return ;
	temp_ptr = (*stack_2)->next;
	(*stack_2)->next = NULL;
	ps_lstadd_front(stack_1, *stack_2);
	*stack_2 = temp_ptr;
	if (flag == 1)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

void	ps_rotate(t_dlist **stack, int flag)
{
	t_dlist	*temp_ptr;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp_ptr = *stack;
	*stack = (*stack)->next;
	temp_ptr->next = NULL;
	ps_lstadd_back(stack, temp_ptr);
	if (flag == 1)
		ft_putstr_fd("ra\n", 1);
	else if (flag == 2)
		ft_putstr_fd("rb\n", 1);
}

void	ps_reverse_rotate(t_dlist **stack, int flag)
{
	t_dlist	*temp_node;
	t_dlist	*temp_ptr;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp_node = *stack;
	while (temp_node->next)
	{
		temp_ptr = temp_node;
		temp_node = temp_node->next;
	}
	temp_ptr->next = NULL;
	ps_lstadd_front(stack, temp_node);
	if (flag == 1)
		ft_putstr_fd("rra\n", 1);
	else if (flag == 2)
		ft_putstr_fd("rrb\n", 1);
}

void	ps_init(t_dlist **stack_a, int argc, int *num_arr)
{
	int	i;
	int	j;
	int	content;

	i = 0;
	while (++i < argc)
	{
		content = 0;
		j = 0;
		while (++j < argc)
			if (num_arr[j] < num_arr[i])
				content++;
		ps_lstadd_back(stack_a, ps_lstnew(content));
	}
}
