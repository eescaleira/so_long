/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:29:36 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/18 19:27:27 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"
#include "../get_next_line/get_next_line_bonus.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*img_pixels;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct	s_image{
	t_data	*wall;
	t_data 	*floor;
	t_data	*exit;
	t_data	*blocked_exit;
	t_data	*collectible;
	t_data	*player;
}				t_image;

typedef struct	player{
	int		x;
	int		y;
	int		collectibles;
}				t_player;

typedef struct	map{
	int		width;
	int		height;
	int 	collectibles;
	char	**map_c;
}				t_map;
	
typedef struct	s_mlx_data{
	void		*mlx;
	void		*mlx_win;
	t_image		*imgs;
	t_map		*map;
	t_player	*player;
}				t_mlx_data;

/* innit */
void innit_window(t_mlx_data *mlx_data);
void innit_img(void *mlx, t_data *img, char *path);
void create_images(t_mlx_data *data);

/* handle input */
int handle_input(int keycode, t_mlx_data *data);

/* map handling */
void copy_map(char **map, char *map_name);

/* render */
void put_wall(t_mlx_data *data, int x, int y);
void put_floor(t_mlx_data *data, int x, int y);
void put_exit(t_mlx_data *data, int x, int y);
void put_blocked_exit(t_mlx_data *data, int x, int y);
void put_collectible(t_mlx_data *data, int x, int y);
void put_player(t_mlx_data *data, int x, int y);


void color_screen(t_mlx_data *data, int color);
void	my_pixel_put_image(t_data *data, int x, int y, int color);

/* frees */
int destroy_window(t_mlx_data *mlx_data);
void destroy_images(t_mlx_data *data);

#endif

/* mlx_hoop_hook  para  animacoes*/