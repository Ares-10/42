/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:38:37 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/01/19 18:05:00 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	ps_lstadd_back(t_deque **lst, t_deque *new)
{
	t_deque	*lst_p;

	if (*lst == 0)
		*lst = new;
	else
	{
		lst_p = ps_lstlast(*lst);
		lst_p->next = new;
	}
}

void	ps_lstadd_front(t_deque **lst, t_deque *new)
{
	if (*lst == 0)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

t_deque	*ps_lstlast(t_deque *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_deque	*ps_lstnew(int content)
{
	t_deque	*node;

	node = (t_deque *)malloc(sizeof(t_deque));
	if (!node)
		return (0);
	node->num = content;
	node->next = 0;
	return (node);
}

void	ps_lstclear(t_deque **lst)
{
	t_deque	*tmp;

	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
