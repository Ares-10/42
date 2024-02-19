/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_graphic_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:27:24 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/20 08:15:37 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_graphic.h"
#include "so_long.h"

void	draw_block(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	block_wide;
	int	block_height;

	block_wide = data->win_width / data->map_width;
	block_height = data->win_height / data->map_heigth;
	i = -1;
	while (++i < block_height)
	{
		j = -1;
		while (++j < block_wide)
			my_mlx_pixel_put(data,
				j + x * block_wide, i + y * block_height, color);
	}
}

void	move_player(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		return ;
	data->move_count++;
	data->map[y][x] = 'P';
	data->map[data->player_ypos][data->player_xpos] = '0';
	data->player_xpos = x;
	data->player_ypos = y;
}

void	init_data(t_data *data, char **map)
{
	data->mlx = mlx_init();
	data->move_count = 0;
	data->map = map;
	data->map_heigth = -1;
	while (map[++data->map_heigth])
	{
		data->map_width = -1;
		while (map[data->map_heigth][++data->map_width])
		{
			if (map[data->map_heigth][data->map_width] == 'P')
			{
				data->player_xpos = data->map_width;
				data->player_ypos = data->map_heigth;
			}
		}
	}
	data->win_width = 0;
	data->win_height = 0;
	while (data->win_width < 960 - data->map_width)
		data->win_width += data->map_width;
	while (data->win_height < 540 - data->map_heigth)
		data->win_height += data->map_heigth;
}
