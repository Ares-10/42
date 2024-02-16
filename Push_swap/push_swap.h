/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:44 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/16 16:28:24 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A_H_B_H 0
# define A_H_B_L 1
# define A_L_B_H 2
# define A_L_B_L 3

# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_dlist
{
	int				num;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

/* push_swap_func */
void	ps_init(t_dlist **stack_a, t_dlist **stack_b, int argc, int *int_arr);
void	ps_lstmove_atob(t_dlist **stack_a, t_dlist **stack_b, int n);
void	ps_sort(int *arr, t_dlist **stack_a, t_dlist **stack_b);
int		ps_getpushpos(int pull_num, t_dlist *lst);
int		ps_issorted(t_dlist *stack);
void	ps_short_sort(t_dlist **stack_a, t_dlist **stack_b);
void	ps_check_best(int *check_best, t_dlist *stack_a, t_dlist *stack_b);

int		ps_lstsize(t_dlist *lst);
int		ps_lstget(int index, t_dlist *lst);
t_dlist	*ps_lstlast(t_dlist *lst);

void	ps_swap(t_dlist **stack, int flag);
void	ps_push(t_dlist **stack_a, t_dlist **stack_b, int flag);
void	ps_rotate(t_dlist **stack, int flag);
void	ps_reverse_rotate(t_dlist **stack, int flag);
void	ps_rr(t_dlist **stack_a, t_dlist **stack_b);
void	ps_rrr(t_dlist **stack_a, t_dlist **stack_b);

#endif