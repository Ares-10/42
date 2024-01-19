/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:41:21 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/01/19 19:11:57 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

int	ps_lstsize(t_deque *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 1;
	while (lst->next)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

int	ps_lstget(int index, t_deque *lst)
{
	while (lst && index--)
		lst = lst->next;
	return (lst->num);
}
