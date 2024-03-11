/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:57:40 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/03/11 21:14:26 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_msg	g_msg;

void	client_handler(int sig)
{
	ft_printf("%d\n", sig);
}

void	error(char *err_msg)
{
	ft_printf("Error\n%s\n", err_msg);
	exit(EXIT_FAILURE);
}

void	handler(int sig)
{
	int	i;
	int	n;

	if (sig == SIGUSR2)
	{
		i = -1;
		n = 1;
		while (++i < g_msg.i)
			n *= 2;
		g_msg.c += n;
	}
	g_msg.i++;
	if (g_msg.i == 8)
	{
		ft_putchar_fd(g_msg.c, 1);
		g_msg.i = 0;
		g_msg.c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	g_msg.i = 0;
	g_msg.c = 0;
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		sleep(1);
}
