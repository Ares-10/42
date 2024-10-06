/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_graphic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:47:53 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/03/30 14:01:33 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_GRAPHIC_H
# define SL_GRAPHIC_H

# include "minilibx_opengl_20191021/mlx.h"

# define KEY_PRESS		2
# define DESTROY_NOTIFY	17
# define ESC			53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124

typedef struct s_images
{
	void	*img_1;
	void	*img_0;
	void	*img_c;
	void	*img_p;
	void	*img_e;
}	t_images;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			win_width;
	int			win_height;
	int			map_width;
	int			map_heigth;
	int			player_xpos;
	int			player_ypos;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			move_count;
	t_images	images;
}	t_data;

int		close_callback(void);
void	init_data(t_data *data, char **map);
void	draw_block(t_data *data, int x, int y, void *img);
int		count_coin(char **map);

#endif