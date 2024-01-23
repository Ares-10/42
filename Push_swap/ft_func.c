/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:30:54 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/01/23 16:43:08 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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
	while (*str && *str >= '0' && *str <= '9')
	{
		n = n * 10 + *str - '0';
		str++;
	}
	if (is_n % 2 == 1)
		return ((int)-n);
	return ((int)n);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

static void	ft_putnbr_fd_1(long n, int fd)
{
	char	ch;

	if (n)
	{
		ft_putnbr_fd_1(n / 10, fd);
		ch = n % 10 + '0';
		write(fd, &ch, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (n < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	if (!n)
		write(fd, "0", 1);
	else
		ft_putnbr_fd_1(num, fd);
}
