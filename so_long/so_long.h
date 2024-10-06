/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:40:11 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/03/30 14:33:49 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

# include "Libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "sl_graphic.h"

void	start_graphic(char **map);

void	strsfree(char **ptr);

/* sl_error */
void	error(void);

/* sl_mapcheck */
void	check_map(char **map);

/* sl_queue */
void	queue_push_xypos(t_list **queue, int xpos, int ypos);
void	*queue_pop(t_list **queue);

#endif