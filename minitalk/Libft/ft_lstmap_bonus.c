/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:32:09 by hyungcho          #+#    #+#             */
/*   Updated: 2023/11/07 16:07:32 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*node;
	void	*cnt;

	node = 0;
	cnt = 0;
	while (lst)
	{
		cnt = f(lst->content);
		result = ft_lstnew(cnt);
		if (!result)
		{
			free(cnt);
			ft_lstclear(&node, del);
			return ((void *)(0));
		}
		ft_lstadd_back(&node, result);
		lst = lst->next;
	}
	result = 0;
	return (node);
}
