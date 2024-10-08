/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:56:37 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/03/30 14:48:16 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	strsfree(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
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
	char	*temp;

	new_line = get_next_line(fd);
	if (!new_line)
		error();
	line = ft_strdup("");
	while (new_line)
	{
		temp = line;
		line = ft_strjoin(line, new_line);
		free(new_line);
		free(temp);
		new_line = get_next_line(fd);
	}
	map = ft_split(line, '\n');
	free(line);
	if (!map)
		error();
	if (close(fd))
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
	start_graphic(map);
}
