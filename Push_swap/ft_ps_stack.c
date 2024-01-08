/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_(*stack).c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:30:11 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/01/07 20:45:54 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_swap(t_list **stack, int flag)
{
	t_list	*temp_ptr1;
	t_list	*temp_ptr2;
	
	temp_ptr1 = *stack;
	temp_ptr2 = (*stack)->next;
	*stack = (*stack)->next->next;
	ft_lstadd_front(stack, temp_ptr1);
	ft_lstadd_front(stack, temp_ptr2);
	if (flag == 1)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	ft_ps_push(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*temp_ptr;

	temp_ptr = (*stack_b)->next;
	(*stack_b)->next = NULL;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = temp_ptr;
	if (flag == 1)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

void	ft_ps_rotate(t_list **stack, int flag)
{
	t_list	*temp_ptr;
	
	temp_ptr = *stack;
	*stack = (*stack)->next;
	temp_ptr->next = NULL;
	ft_lstadd_back(stack, temp_ptr);
	if (flag == 1)
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	ft_ps_rrotate(t_list **stack, int flag)
{
	t_list	*temp_node;
	t_list	*temp_ptr;
	
	temp_node = *stack;
	while (temp_node->next)
	{
		temp_ptr = temp_node;
		temp_node = temp_node->next;
	}
	temp_ptr->next = NULL;
	ft_lstadd_front(stack, temp_node);
	if (flag == 1)
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}

void	ft_ps_init(t_list **stack, int argc, char **argv)
{
	int		i;
	void	*content;

	i = 0;
	while (++i < argc)
	{
		content = (int *)malloc(sizeof(int *));
		*((int *)content) = ft_atoi(argv[i]);
		ft_lstadd_back(stack, ft_lstnew(content));
	}
}
