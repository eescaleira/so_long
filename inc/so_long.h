/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:29:36 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/05 02:06:43 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../my_library/lib.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data {
	void	*img;
	char	*img_pixels;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct s_image{
	t_data	*wall;
	t_data	*floor;
	t_data	*exit;
	t_data	*blocked_exit;
	t_data	*collectible;
	t_data	*player;
}				t_image;

typedef struct player{
	int		x;
	int		y;
	int		collectibles;
	int		moves;
}				t_player;

typedef struct map{
	int		width;
	int		height;
	int		collectibles;
	int		exit_x;
	int		exit_y;
	char	**map_c;
}				t_map;

typedef struct s_mlx_data{
	void		*mlx;
	void		*mlx_win;
	t_image		*imgs;
	t_map		*map;
	t_player	*player;
}				t_mlx_data;

/* innit */
void	innit_window(t_mlx_data *mlx_data);
void	innit_img(void *mlx, t_data *img, char *path);
void	create_images(t_mlx_data *data);
void	innit_variables(t_mlx_data *data);

/* handle input */
int		handle_input(int keycode, t_mlx_data *data);

/* map handling */
int		create_map(t_mlx_data *data);
void	check_map(t_mlx_data *data, char *map_name);
int		copy_map(char ***map, char *map_name);
int		flood_fill(char **map, int x, int y, t_player *player);
int		check_walls(t_map *map);
int		check_map_chars(t_mlx_data *data, int i, int j);
int		check_char(t_mlx_data *data, int i, int j);
void	write_map(char ***map, char **new_map, char *line, int i);

/* render */
void	put_block(t_mlx_data *data, int j, int i);
void	put_wall(t_mlx_data *data, int x, int y);
void	put_floor(t_mlx_data *data, int x, int y);
void	put_exit(t_mlx_data *data, int x, int y);
void	put_blocked_exit(t_mlx_data *data, int x, int y);
void	put_collectible(t_mlx_data *data, int x, int y);
void	put_player(t_mlx_data *data, int x, int y);

/* frees */
int		destroy_window(t_mlx_data *mlx_data);
void	destroy_images(t_mlx_data *data);
int		free_map(char **map);
void	free_map_play(t_mlx_data *data);

#endif
