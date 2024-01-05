/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:51:01 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/05 01:13:00 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	innit_window(t_mlx_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx,
			data->map->width * 32, data->map->height * 32, "first window");
}

void	innit_img(void *mlx, t_data *img, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	img->img_pixels = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}

void	create_images(t_mlx_data *data)
{
	data->imgs = malloc(sizeof(t_image));
	data->imgs->wall = malloc(sizeof(t_data));
	innit_img(data->mlx, data->imgs->wall, "./textures/wall.xpm");
	data->imgs->floor = malloc(sizeof(t_data));
	innit_img(data->mlx, data->imgs->floor, "./textures/floor.xpm");
	data->imgs->exit = malloc(sizeof(t_data));
	innit_img(data->mlx, data->imgs->exit, "./textures/exit.xpm");
	data->imgs->blocked_exit = malloc(sizeof(t_data));
	innit_img(data->mlx, data->imgs->blocked_exit, "./textures/floor.xpm");
	data->imgs->collectible = malloc(sizeof(t_data));
	innit_img(data->mlx, data->imgs->collectible, "./textures/collectible.xpm");
	data->imgs->player = malloc(sizeof(t_data));
	innit_img(data->mlx, data->imgs->player, "./textures/player.xpm");
}

void	innit_variables(t_mlx_data *data)
{
	data->player->collectibles = 0;
	data->map->collectibles = 0;
	data->player->moves = 0;
	data->player->x = -1;
	data->map->exit_x = -1;
}
