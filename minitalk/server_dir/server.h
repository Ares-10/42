/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:21:42 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/03/11 16:51:02 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../lib/include/libft.h"
# include "../lib/include/ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_msg
{
	int	c;
	int	i;
}	t_msg;


#endif