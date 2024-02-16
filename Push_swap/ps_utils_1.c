/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:38:37 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/16 16:15:28 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	ps_lstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*lst_p;

	if (*lst == 0)
		*lst = new;
	else
	{
		lst_p = ps_lstlast(*lst);
		lst_p->next = new;
		new->prev = lst_p;
		new->next = NULL;
	}
}

void	ps_lstadd_front(t_dlist **lst, t_dlist *new)
{
	if (*lst == 0)
		*lst = new;
	else
	{
		(*lst)->prev = new;
		new->next = *lst;
		*lst = new;
	}
}

t_dlist	*ps_lstlast(t_dlist *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_dlist	*ps_lstnew(int content)
{
	t_dlist	*node;

	node = (t_dlist *)malloc(sizeof(t_dlist));
	if (!node)
		return (0);
	node->num = content;
	node->next = 0;
	node->prev = NULL;
	return (node);
}

void	ps_lstclear(t_dlist **lst)
{
	t_dlist	*tmp;

	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
