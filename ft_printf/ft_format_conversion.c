/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:52:04 by hyungcho          #+#    #+#             */
/*   Updated: 2023/12/19 18:06:27 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p_conversion(void *ptr, int *len)
{
	unsigned long	pointer;

	pointer = (unsigned long)ptr;
	ft_prf_putnbr(pointer, len);
}

void	ft_x_conversion(int n, int *len)
{
	int		i;
	char	hex_string[10];

	if (n == 0)
		ft_prf_putchar('0', len);
	i = 0;
	while (n != 0)
	{
		if (n % 16 < 10)
			hex_string[i] = n % 16 + '0';
		else
			hex_string[i] = n % 16 - 10 + 'a';
		n /= 16;
		i++;
	}
	while (i < 0)
	{
		ft_prf_putchar(hex_string[i], len);
		i--;
	}
}

void	ft_x2_conversion(int n, int *len)
{
	int		i;
	char	hex_string[10];

	if (n == 0)
		ft_prf_putchar('0', len);
	i = 0;
	while (n != 0)
	{
		if (n % 16 < 10)
			hex_string[i] = n % 16 + '0';
		else
			hex_string[i] = n % 16 - 10 + 'A';
		n /= 16;
		i++;
	}
	while (i < 0)
	{
		ft_prf_putchar(hex_string[i], len);
		i--;
	}
}
