/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:01:24 by hyungcho          #+#    #+#             */
/*   Updated: 2024/08/22 21:29:17 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:21:42 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/03/30 14:51:29 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../lib/include/libft.h"
# include "../lib/include/ft_printf.h"
# include <unistd.h>
# include <signal.h>

typedef struct s_msg
{
	int	c;
	int	i;
}	t_msg;

#endif