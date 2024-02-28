/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:55:54 by hyungcho          #+#    #+#             */
/*   Updated: 2023/10/26 22:57:14 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd_1(long n, int fd)
{
	if (n)
	{
		ft_putnbr_fd_1(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (n < 0)
	{
		num = -num;
		ft_putchar_fd('-', fd);
	}
	if (!n)
		ft_putchar_fd('0', fd);
	else
		ft_putnbr_fd_1(num, fd);
}
