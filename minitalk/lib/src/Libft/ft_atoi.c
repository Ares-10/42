/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:50:09 by hyungcho          #+#    #+#             */
/*   Updated: 2023/10/28 20:53:20 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		is_n;
	long	n;

	is_n = 0;
	n = 0;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (*str && (*str == '-' || *str == '+'))
		if (*str++ == '-')
			is_n++;
	while (*str && ft_isdigit(*str))
	{
		n = n * 10 + *str - '0';
		str++;
	}
	if (is_n % 2 == 1)
		return ((int)-n);
	return ((int)n);
}
