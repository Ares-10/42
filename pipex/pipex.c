/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:58:30 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/28 20:23:09 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		ft_printf("%s\n", envp[i]);
	}
	ft_printf("\n\n%d %s", argc, *argv);
}