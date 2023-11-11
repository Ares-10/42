/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:01:54 by hyungcho          #+#    #+#             */
/*   Updated: 2023/11/11 19:32:36 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	// int		fd;
	// char	*line;

	// fd = open("test.txt", O_RDONLY);
	// line = get_next_line(open("test.txt", O_RDONLY));
	printf("%s", get_next_line(open("test.txt", O_RDONLY)));
	// while (*line)
	// {
	// 	printf("%s", line);
	// 	line = get_next_line(fd);
	// }
	return (0);
}
