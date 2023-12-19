/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:53:38 by hyungcho          #+#    #+#             */
/*   Updated: 2023/12/19 20:13:02 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static void	ft_s_conversion(char *str, int *len);
static void	ft_p_conversion(void *ptr, int *len);
static void	ft_u_conversion(unsigned int n, int *len);
static void	ft_format_conversion(va_list ap, char ch, int *len);

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			len;

	len = 0;
	if (!str)
		return (0);
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			len++;
		}
		else
		{
			str++;
			ft_format_conversion(ap, *str, &len);
		}
		str++;
	}
	va_end(ap);
	return (len);
}

void	ft_format_conversion(va_list ap, char ch, int *len)
{
	if (ch == 'c')
		ft_prf_putchar(va_arg(ap, int), len);
	else if (ch == 's')
		ft_s_conversion(va_arg(ap, char *), len);
	else if (ch == 'p')
		ft_p_conversion(va_arg(ap, void *), len);
	else if (ch == 'd')
		ft_prf_putnbr(va_arg(ap, int), len);
	else if (ch == 'i')
		ft_prf_putnbr(va_arg(ap, int), len);
	else if (ch == 'u')
		ft_u_conversion(va_arg(ap, unsigned int), len);
	else if (ch == 'x')
		ft_prf_itohex(va_arg(ap, int), len, 1);
	else if (ch == 'X')
		ft_prf_itohex(va_arg(ap, int), len, 2);
	else if (ch == '%')
		ft_prf_putchar('%', len);
}

void	ft_s_conversion(char *str, int *len)
{
	if (str == NULL)
	{
		ft_prf_putstr("(null)", len);
		return ;
	}
	ft_prf_putstr(str, len);
}

void	ft_p_conversion(void *ptr, int *len)
{
	unsigned long long	address;
	char				hex_string[20];
	int					i;

	ft_prf_putstr("0x", len);
	if (ptr == NULL)
	{
		ft_prf_putchar('0', len);
		return ;
	}
	address = (unsigned long long)ptr;
	i = 0;
	while (address)
	{
		if (address % 16 < 10)
			hex_string[i] = address % 16 + '0';
		else
			hex_string[i] = address % 16 - 10 + 'a';
		address /= 16;
		i++;
	}
	while (i--)
		ft_prf_putchar(hex_string[i], len);
}

void	ft_u_conversion(unsigned int n, int *len)
{
	if (!n)
		ft_prf_putchar('0', len);
	else
		ft_prf_putnbr_1(n, len);
}
