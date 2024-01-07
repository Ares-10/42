/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:44 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/01/07 21:27:40 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS 1
# define ERROR 0

# include "libft.h"
# include <stdlib.h>

void	ft_ps_swap(t_list **stack, int flag);
void	ft_ps_push(t_list **stack_a, t_list **stack_b, int flag);
void	ft_ps_rotate(t_list **stack, int flag);
void	ft_ps_rrotate(t_list **stack, int flag);
void	ft_ps_init(t_list **stack, int argc, char **argv);

#endif