/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:54 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/01/05 19:48:56 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ps_puterr(void)
{
	ft_putstr_fd("ERROR\n", 2);
	return (ERROR);
}

int	ft_ps_check_arg(int argc, char **argv)
{
	int	check_num[argc];
	int	i;
	int n;

	i = 0;
	while (++i < argc)
		check_num[i++] = ERROR;
	i = 0;
	while (++i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n <= 0)
			return (ft_ps_puterr());
		check_num[n] = SUCCESS;
	}
	i = 0;
	while (++ i < argc)
		if (check_num[i] == ERROR)
			return (ft_ps_puterr());
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	if (ft_ps_check_arg(argc, argv) == ERROR || argc < 2)
		return (0);
}