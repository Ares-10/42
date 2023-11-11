/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:25:01 by hyungcho          #+#    #+#             */
/*   Updated: 2023/11/11 23:28:42 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	gnl_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == 0)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	gnl_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

t_list	*gnl_lstnew(int fd)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->fd = fd;
	node->next = 0;
	return (node);
}
