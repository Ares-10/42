/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:56:37 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/03/07 18:28:55 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

static int	check_arg_and_get_fd(int argc, char **argv)
{
	int	len;
	int	fd;

	if (argc != 2)
		error();
	len = ft_strlen(argv[1]);
	if (len < 5)
		error();
	if (argv[1][len - 4] != '.' || argv[1][len - 3] != 'b'
		|| argv[1][len - 2] != 'e' || argv[1][len - 1] != 'r')
		error();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error();
	return (fd);
}

static char	**get_map(int fd)
{
	char	**map;
	char	*line;
	char	*new_line;

	new_line = get_next_line(fd);
	if (!new_line)
		error();
	line = "";
	while (new_line)
	{
		line = ft_strjoin(line, new_line);
		new_line = get_next_line(fd);
	}
	map = ft_split(line, '\n');
	if (!map)
		error();
	return (map);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;

	fd = check_arg_and_get_fd(argc, argv);
	map = get_map(fd);
	check_map(map);
	start_grapic(map);
}
