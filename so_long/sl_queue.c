/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 03:40:43 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/18 16:08:32 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	queue_push_xypos(t_list **queue, int xpos, int ypos)
{
	int	*xypos;

	xypos = (int *)malloc(sizeof(int) * 2);
	if (!xypos)
		error();
	xypos[0] = xpos;
	xypos[1] = ypos;
	ft_lstadd_back(queue, ft_lstnew(xypos));
}

void	*queue_pop(t_list **queue)
{
	t_list	*delete_node;
	int		*xypos;

	if (!*queue)
		return (0);
	xypos = (int *)malloc(sizeof(int) * 2);
	if (!xypos)
		error();
	xypos[0] = ((int *)((*queue)->content))[0];
	xypos[1] = ((int *)((*queue)->content))[1];
	delete_node = *queue;
	*queue = (*queue)->next;
	ft_lstdelone(delete_node, free);
	return (xypos);
}
