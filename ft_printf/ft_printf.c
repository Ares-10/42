/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:53:38 by hyungcho          #+#    #+#             */
/*   Updated: 2023/12/19 18:07:19 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static void	ft_format_conversion(va_list ap, char ch, int *len)
{
	if (ch == 'c')
		ft_prf_putchar(va_arg(ap, int), len);
	else if (ch == 's')
		ft_prf_putstr(va_arg(ap, char *), len);
	else if (ch == 'p')
		ft_p_conversion(va_arg(ap, void *), len);
	else if (ch == 'd')
		ft_prf_putnbr(va_arg(ap, int), len);
	else if (ch == 'i')
		ft_prf_putnbr(va_arg(ap, int), len);
	else if (ch == 'u')
		ft_prf_putnbr(va_arg(ap, unsigned int), len);
	else if (ch == 'x')
		ft_x_conversion(va_arg(ap, int), len);
	else if (ch == 'X')
		ft_x2_conversion(va_arg(ap, int), len);
	else if (ch == '%')
		ft_prf_putchar('%', len);
}

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
