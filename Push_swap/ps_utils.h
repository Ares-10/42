/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:08:53 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/16 16:15:28 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_UTILS_H
# define PS_UTILS_H

# include "push_swap.h"

t_dlist	*ps_lstnew(int content);
void	ps_lstadd_front(t_dlist **lst, t_dlist *new);
int		ps_lstsize(t_dlist *lst);
t_dlist	*ps_lstlast(t_dlist *lst);
void	ps_lstadd_back(t_dlist **lst, t_dlist *new);
void	ps_lstclear(t_dlist **lst);
int		ps_lstget(int index, t_dlist *lst);

#endif