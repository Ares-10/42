/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:32:09 by hyungcho          #+#    #+#             */
/*   Updated: 2023/10/28 14:41:03 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*iter;

	if (lst)
		result = ft_lstnew(f(lst->content));
	else
		return (0);
	iter = result;
	while (lst->next)
	{
		lst = lst->next;
		iter->next = ft_lstnew(f(lst->content));
		if (iter->next == 0)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		iter = iter->next;
	}
	return (result);
}
