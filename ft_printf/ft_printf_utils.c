/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:53:51 by hyungcho          #+#    #+#             */
/*   Updated: 2023/12/19 18:11:47 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_prf_putchar(char c, int *len)
{
	write(1, &c, 1);
	len++;
}

void	ft_prf_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	write(1, s, i);
	len += i;
}

static void	ft_prf_putnbr_1(long n, int *len)
{
	if (n)
	{
		ft_prf_putnbr_1(n / 10, len);
		ft_prf_putchar(n % 10 + '0', len);
	}
}

void	ft_prf_putnbr(int n, int *len)
{
	long	num;

	num = n;
	if (n < 0)
	{
		num = -num;
		ft_prf_putchar('-', len);
	}
	if (!n)
		ft_prf_putchar('0', len);
	else
		ft_prf_putnbr_1(num, len);
}
