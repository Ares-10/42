/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_graphic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:34:32 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/03/30 14:49:14 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_graphic.h"
#include "so_long.h"

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
				draw_block(data, xpos, ypos, data->images.img_1);
			if (data->map[ypos][xpos] == '0')
				draw_block(data, xpos, ypos, data->images.img_0);
			if (data->map[ypos][xpos] == 'P')
				draw_block(data, xpos, ypos, data->images.img_p);
			if (data->map[ypos][xpos] == 'E')
				draw_block(data, xpos, ypos, data->images.img_e);
			if (data->map[ypos][xpos] == 'C')
				draw_block(data, xpos, ypos, data->images.img_c);
		}
	}
	return (0);
}

static void	move_player(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = data->player_xpos;
	y = data->player_ypos;
	if (keycode == KEY_LEFT || keycode == KEY_A)
		x--;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		x++;
	else if (keycode == KEY_UP || keycode == KEY_W)
		y--;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		y++;
	else
		return ;
	if (data->map[y][x] == '1'
		|| (data->map[y][x] == 'E' && count_coin(data->map) != 0))
		return ;
	data->move_count++;
	data->map[y][x] = 'P';
	data->map[data->player_ypos][data->player_xpos] = '0';
	data->player_xpos = x;
	data->player_ypos = y;
}

static int	key_press(int keycode, t_data *data)
{
	int	move_count;

	move_count = data->move_count;
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	move_player(keycode, data);
	draw(data);
	if (data->move_count != move_count)
	{
		ft_putstr_fd("move count: ", 1);
		ft_putnbr_fd(data->move_count, 1);
		ft_putendl_fd("", 1);
	}
	return (0);
}

void	start_graphic(char **map)
{
	t_data	data;

	init_data(&data, map);
	data.win = mlx_new_window(data.mlx,
			data.win_width, data.win_height, "so_long");
	data.img = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.addr = mlx_get_data_addr(data.img,
			&data.bpp, &data.line_length, &data.endian);
	draw(&data);
	mlx_hook(data.win, KEY_PRESS, 0, key_press, &data);
	mlx_hook(data.win, DESTROY_NOTIFY, 0, close_callback, &data);
	mlx_loop(data.mlx);
	exit(0);
}
