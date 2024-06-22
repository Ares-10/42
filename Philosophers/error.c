/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:55:50 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/06/23 03:13:39 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_puterr(char *msg)
{
	int	len;

	len = 0;
	while (msg[len])
		len++;
	write(2, "Error\n", 6);
	write(2, msg, len);
	exit(EXIT_FAILURE);
}
