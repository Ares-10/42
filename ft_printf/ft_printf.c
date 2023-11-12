/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:53:38 by hyungcho          #+#    #+#             */
/*   Updated: 2023/11/12 22:25:58 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_printf(const char *argv, ...)
{
	va_list	ap;

	va_start(ap, argv);
	while (argc-- > 0)
		printf("%d ", va_arg(ap, int));
	va_end(ap);
	printf("\n");
}
