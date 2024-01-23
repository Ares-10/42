/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_func_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:24:09 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/01/23 16:35:18 by johyeongeun      ###   ########.fr       */
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