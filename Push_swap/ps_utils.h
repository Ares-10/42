/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:08:53 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/01/19 18:21:50 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_UTILS_H
# define PS_UTILS_H

# include "push_swap.h"

t_deque	*ps_lstnew(int content);
void	ps_lstadd_front(t_deque **lst, t_deque *new);
int		ps_lstsize(t_deque *lst);
t_deque	*ps_lstlast(t_deque *lst);
void	ps_lstadd_back(t_deque **lst, t_deque *new);
void	ps_lstclear(t_deque **lst);
int		ps_lstget(int index, t_deque *lst);

#endif