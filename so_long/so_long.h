/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:40:11 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/28 19:26:02 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

# include "Libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "sl_graphic.h"

void	start_grapic(char **map);

/* sl_error */
void	error(void);

/* sl_mapcheck */
void	check_map(char **map);

/* sl_queue */
void	queue_push_xypos(t_list **queue, int xpos, int ypos);
void	*queue_pop(t_list **queue);

#endif