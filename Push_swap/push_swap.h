/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:44 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/06 20:17:01 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS 1
# define ERROR 0

# define A_H_B_H 0
# define A_H_B_L 1
# define A_L_B_H 2
# define A_L_B_L 3

# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_deque
{
	int				num;
	struct s_deque	*next;
	struct s_deque	*prev;
}	t_deque;

/* push_swap_func */
void	ps_init(t_deque **stack_a, t_deque **stack_b, int argc, int *int_arr);
void	ps_lstmove_atob(t_deque **stack_a, t_deque **stack_b, int n);
void	ps_sort(int *arr, t_deque **stack_a, t_deque **stack_b);
int		ps_getpushpos(int pull_num, t_deque *lst);
int		ps_issorted(t_deque *stack);
void	ps_short_sort(t_deque **stack_a, t_deque **stack_b);
void	ps_check_best(int *check_best, t_deque *stack_a, t_deque *stack_b);

int		ps_lstsize(t_deque *lst);
int		ps_lstget(int index, t_deque *lst);
t_deque	*ps_lstlast(t_deque *lst);

void	ps_swap(t_deque **stack, int flag);
void	ps_push(t_deque **stack_a, t_deque **stack_b, int flag);
void	ps_rotate(t_deque **stack, int flag);
void	ps_rrotate(t_deque **stack, int flag);
void	ps_rr(t_deque **stack_a, t_deque **stack_b);
void	ps_rrr(t_deque **stack_a, t_deque **stack_b);

#endif