/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_graphic_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:27:24 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/03/07 20:15:52 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_graphic.h"
#include "so_long.h"

void	draw_block(t_data *data, int x, int y, void *img)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x * 32, y * 32);
}

int	close_callback(void)
{
	exit(0);
	return (0);
}

void	init_images(t_data *data)
{
	int	img_width;
	int	img_height;

	data->images.img_0 = mlx_xpm_file_to_image(data->mlx,
			"./maps/skull_a.xpm", &img_width, &img_height);
	data->images.img_1 = mlx_xpm_file_to_image(data->mlx,
			"./maps/gift.xpm", &img_width, &img_height);
	data->images.img_p = mlx_xpm_file_to_image(data->mlx,
			"./textures/skull_b.xpm", &img_width, &img_height);
	data->images.img_c = mlx_xpm_file_to_image(data->mlx,
			"./textures/crystal.xpm", &img_width, &img_height);
	data->images.img_e = mlx_xpm_file_to_image(data->mlx,
			"./textures/key.xpm", &img_width, &img_height);
	if (!data->images.img_0 || !data->images.img_1 || !data->images.img_p
		|| !data->images.img_c || !data->images.img_e)
		error();
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
	data->win_width = 32 * data->map_width;
	data->win_height = 32 * data->map_heigth;
	init_images(data);
}

int	count_coin(char **map)
{
	int	i;
	int	j;
	int	count_c;

	count_c = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				count_c++;
		}
	}
	return (count_c);
}
