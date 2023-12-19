/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:53:51 by hyungcho          #+#    #+#             */
/*   Updated: 2023/12/19 20:09:34 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_prf_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_prf_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	write(1, s, i);
	*len += i;
}

void	ft_prf_putnbr_1(long n, int *len)
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

void	ft_prf_itohex(int n, int *len, int flag)
{
	int					i;
	char				hex_string[20];
	unsigned long long	num;

	i = 0;
	num = n;
	if (n == 0)
		ft_prf_putchar('0', len);
	if (n < 0)
		num += 2L * 16 * 16 * 16 * 16 * 16 * 16 * 16 * 16;
	while (num)
	{
		if (num % 16 < 10)
			hex_string[i++] = num % 16 + '0';
		else if (flag == 1)
			hex_string[i++] = num % 16 - 10 + 'a';
		else
			hex_string[i++] = num % 16 - 10 + 'A';
		num /= 16;
	}
	if (n < 0)
		i--;
	while (i--)
		ft_prf_putchar(hex_string[i], len);
}
