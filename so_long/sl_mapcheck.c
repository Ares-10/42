/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:19:27 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/03/30 14:46:35 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_contents(char **map);
static void	check_map_validation(char **map);
static int	check_map_bfs(char **map, char **visited, t_list **queue, char c);
static char	**strsdup(char **strs);

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

void	check_map_contents(char **map)
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

int	check_map_bfs(char **map, char **visited, t_list **queue, char content)
{
	int		*xypos;

	while (*queue)
	{
		xypos = (int *)queue_pop(queue);
		if (map[xypos[1]][xypos[0]] == 'P')
		{
			free(xypos);
			return (1);
		}
		if (map[xypos[1]][xypos[0]] == '1' || visited[xypos[1]][xypos[0]] == '2'
			|| (content == 'C' && map[xypos[1]][xypos[0]] == 'E'))
		{
			free(xypos);
			continue ;
		}
		visited[xypos[1]][xypos[0]] = '2';
		queue_push_xypos(queue, xypos[0] + 1, xypos[1]);
		queue_push_xypos(queue, xypos[0], xypos[1] + 1);
		queue_push_xypos(queue, xypos[0] - 1, xypos[1]);
		queue_push_xypos(queue, xypos[0], xypos[1] - 1);
		free(xypos);
	}
	strsfree(visited);
	return (0);
}

void	check_map_validation(char **map)
{
	int		xpos;
	int		ypos;
	t_list	*queue;
	char	**visited;

	ypos = 0;
	while (map[++ypos])
	{
		xpos = 0;
		while (map[ypos][++xpos])
		{
			if (map[ypos][xpos] == 'E' || map[ypos][xpos] == 'C')
			{
				queue = NULL;
				queue_push_xypos(&queue, xpos, ypos);
				visited = strsdup(map);
				if (!visited
					|| !check_map_bfs(map, visited, &queue, map[ypos][xpos]))
					error();
				strsfree(visited);
				ft_lstclear(&queue, free);
			}
		}
	}
}

char	**strsdup(char **strs)
{
	char	**new_strs;
	int		str_count;
	int		i;

	str_count = 0;
	while (strs[str_count])
		str_count++;
	new_strs = (char **)malloc(sizeof(char *) * str_count + 1);
	i = -1;
	while (++i < str_count)
		new_strs[i] = ft_strdup(strs[i]);
	new_strs[i] = NULL;
	return (new_strs);
}
