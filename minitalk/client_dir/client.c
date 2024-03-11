/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:57:40 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/03/11 21:14:24 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	error(char *err_msg)
{
	ft_printf("Error\n%s\n", err_msg);
	exit(EXIT_FAILURE);
}

static int	argtopid(int argc, char **argv)
{
	long	pid;
	char	*str;

	if (argc != 3)
		error("pid");
	str = argv[1];
	pid = 0;
	if (!*str || !ft_isdigit(*str))
		error("pid");
	if (*str == '0' && *(str + 1) != '\0')
		error("pid");
	while (*str && ft_isdigit(*str))
	{
		pid = pid * 10 + *str - '0';
		str++;
		if (pid > __INT32_MAX__)
			return (-1);
	}
	if (*str != '\0')
		error("pid");
	if (argv[2][0] == '\0')
		error("message");
	return ((int)pid);
}

void	send_str(int pid, char *msg)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	while (msg[++i])
	{
		c = msg[i];
		j = -1;
		while (++j < 8)
		{
			if (c % 2 == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			c = c / 2;
			usleep(50);
		}
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;

	pid = argtopid(argc, argv);
	send_str(pid, argv[2]);
}
