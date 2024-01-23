/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:44 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/01/23 16:34:40 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS 1
# define ERROR 0

# define MIN(a, b) a < b ? a : b
# define MAX(a, b) a > b ? a : b

# include <stdlib.h>

typedef struct s_deque
{
	int				num;
	struct s_deque	*next;
	struct s_deque	*prev;
}	t_deque;

/* push_swap_func */
void	ps_swap(t_deque **stack, int flag);
void	ps_push(t_deque **stack_a, t_deque **stack_b, int flag);
void	ps_rotate(t_deque **stack, int flag);
void	ps_rrotate(t_deque **stack, int flag);
void	ps_rr(t_deque **stack_a, t_deque **stack_b);
void	ps_rrr(t_deque **stack_a, t_deque **stack_b);

void	ps_init(t_deque **stack_a, t_deque **stack_b, int argc, char **argv);
void	ps_sort(int size, t_deque **stack_a, t_deque **stack_b);

int		ps_lstsize(t_deque *lst);
int		ps_lstget(int index, t_deque *lst);

/* libft_func */
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);


#endif