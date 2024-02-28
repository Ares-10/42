/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:19:27 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/28 19:08:02 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_contents(char **map)
{
	int	i;
	int	j;
	int	count_c_e_p[3];

	count_c_e_p[0] = 0;
	count_c_e_p[1] = 0;
	count_c_e_p[2] = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				count_c_e_p[0]++;
			else if (map[i][j] == 'E')
				count_c_e_p[1]++;
			else if (map[i][j] == 'P')
				count_c_e_p[2]++;
			else if (!(map[i][j] == '0' || map[i][j] == '1'))
				error();
		}
	}
	if (!count_c_e_p[0] || count_c_e_p[1] != 1 || count_c_e_p[2] != 1)
		error();
}

static char	**strsdup(char **strs)
{
	char	**new_strs;
	int		str_count;
	int		i;

	str_count = 0;
	while (strs[str_count])
		str_count++;
	new_strs = (char **)malloc(sizeof(char *) * str_count);
	i = -1;
	while (++i < str_count)
		new_strs[i] = ft_strdup(strs[i]);
	return (new_strs);
}

static int	check_map_bfs(char **map, t_list **queue, int xpos, int ypos)
{
	int		*xypos;
	char	**visited;

	visited = strsdup(map);
	queue_push_xypos(queue, xpos, ypos);
	while (*queue)
	{
		xypos = (int *)queue_pop(queue);
		if (map[xypos[1]][xypos[0]] == 'E')
		{
			free(visited);
			return (1);
		}
		if (map[xypos[1]][xypos[0]] == '1'
			|| visited[xypos[1]][xypos[0]] == '2')
			continue ;
		visited[xypos[1]][xypos[0]] = '2';
		queue_push_xypos(queue, xypos[0] + 1, xypos[1]);
		queue_push_xypos(queue, xypos[0], xypos[1] + 1);
		queue_push_xypos(queue, xypos[0] - 1, xypos[1]);
		queue_push_xypos(queue, xypos[0], xypos[1] - 1);
	}
	free(visited);
	return (0);
}

static void	check_map_validation(char **map)
{
	int		xpos;
	int		ypos;
	t_list	*queue;

	ypos = 0;
	while (map[++ypos])
	{
		xpos = 0;
		while (map[ypos][++xpos])
		{
			if (map[ypos][xpos] == 'P')
			{
				queue = NULL;
				if (!check_map_bfs(map, &queue, xpos, ypos))
					error();
				ft_lstclear(&queue, free);
				return ;
			}
		}
	}
}

void	check_map(char **map)
{
	int	i;
	int	height;
	int	width;

	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	i = -1;
	while (++i < height)
	{
		if (width != (int)ft_strlen(map[i]))
			error();
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			error();
	}
	i = -1;
	while (++i < width)
		if (map[0][i] != '1' || map[height -1][i] != '1')
			error();
	check_map_contents(map);
	check_map_validation(map);
}
