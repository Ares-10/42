/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:53:38 by hyungcho          #+#    #+#             */
/*   Updated: 2024/02/28 20:31:04 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf_utils.h"

static int	ft_s_conversion(char *str, int *len);
static int	ft_p_conversion(void *ptr, int *len);
static int	ft_u_conversion(unsigned int n, int *len);
static int	ft_format_conversion(va_list *ap, char ch, int *len);

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
			if (ft_prf_putchar(*str, &len) == -1)
				return (-1);
		}
		else
			if (ft_format_conversion(&ap, *(++str), &len) == -1)
				return (-1);
		str++;
	}
	va_end(ap);
	return (len);
}

int	ft_format_conversion(va_list *ap, char ch, int *len)
{
	char	hex_string[10];

	if (ch == 'c')
		return (ft_prf_putchar(va_arg(*ap, int), len));
	else if (ch == 's')
		return (ft_s_conversion(va_arg(*ap, char *), len));
	else if (ch == 'p')
		return (ft_p_conversion(va_arg(*ap, void *), len));
	else if (ch == 'd')
		return (ft_prf_putnbr(va_arg(*ap, int), len));
	else if (ch == 'i')
		return (ft_prf_putnbr(va_arg(*ap, int), len));
	else if (ch == 'u')
		return (ft_u_conversion(va_arg(*ap, unsigned int), len));
	else if (ch == 'x')
		return (ft_prf_itohex(va_arg(*ap, int), hex_string, len, 1));
	else if (ch == 'X')
		return (ft_prf_itohex(va_arg(*ap, int), hex_string, len, 2));
	else if (ch == '%')
		return (ft_prf_putchar('%', len));
	else
		return (-1);
}

int	ft_s_conversion(char *str, int *len)
{
	if (str == NULL)
		return (ft_prf_putstr("(null)", len));
	return (ft_prf_putstr(str, len));
}

int	ft_p_conversion(void *ptr, int *len)
{
	unsigned long long	address;
	char				hex_string[20];
	int					i;

	if (ft_prf_putstr("0x", len) == -1)
		return (-1);
	if (ptr == NULL)
		return (ft_prf_putchar('0', len));
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
		if (ft_prf_putchar(hex_string[i], len) == -1)
			return (-1);
	return (0);
}

int	ft_u_conversion(unsigned int n, int *len)
{
	if (!n)
		return (ft_prf_putchar('0', len));
	else
		return (ft_prf_putnbr_1(n, len));
}
