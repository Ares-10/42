/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_graphic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:34:32 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/20 08:20:05 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_graphic.h"
#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static int	draw(t_data *data)
{
	int	ypos;
	int	xpos;

	ypos = -1;
	while (++ypos < data->map_heigth)
	{
		xpos = -1;
		while (++xpos < data->map_width)
		{
			if (data->map[ypos][xpos] == '1')
				draw_block(data, xpos, ypos, 0x00FF000);
			if (data->map[ypos][xpos] == '0')
				draw_block(data, xpos, ypos, 0x00FFFF00);
			if (data->map[ypos][xpos] == 'P')
				draw_block(data, xpos, ypos, 0x00FF00FF);
			if (data->map[ypos][xpos] == 'E')
				draw_block(data, xpos, ypos, 0x000000FF);
			if (data->map[ypos][xpos] == 'C')
				draw_block(data, xpos, ypos, 0x0000FFFF);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

static int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == LEFT)
		move_player(data, data->player_xpos - 1, data->player_ypos);
	if (keycode == RIGHT)
		move_player(data, data->player_xpos + 1, data->player_ypos);
	if (keycode == UP)
		move_player(data, data->player_xpos, data->player_ypos - 1);
	if (keycode == DOWN)
		move_player(data, data->player_xpos, data->player_ypos + 1);
	draw(data);
	return (0);
}

static int	close_callback(void)
{
	exit(0);
	return (0);
}

void	start_grapic(char **map)
{
	t_data	data;

	init_data(&data, map);
	data.win = mlx_new_window(data.mlx,
			data.win_width, data.win_height, "so_long");
	data.img = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.addr = mlx_get_data_addr(data.img,
			&data.bpp, &data.line_length, &data.endian);
	draw(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

	mlx_hook(data.win, KEY_PRESS, 0, key_press, &data);
	mlx_hook(data.win, DESTROY_NOTIFY, 0, close_callback, &data);
	mlx_loop(data.mlx);
	exit(0);
}
