/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:51:01 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/15 15:06:41 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void innit_window(t_mlx_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 500, 500, "first window");
}

void innit_img(t_mlx_data *data)
{
	data->img.img = mlx_new_image(data->mlx, 500, 500);
	data->img.img_pixels = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
}

void create_images(t_mlx_data *data)
{
	data->imgs->wall = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &data->imgs->wall->width, &data->imgs->wall->height);
	data->imgs->floor = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm", &data->imgs->floor->width, &data->imgs->wall->height);
	data->imgs->exit = mlx_xpm_file_to_image(data->mlx, "./img/exit.xpm", &data->imgs->exit->width, &data->imgs->exit->height);
	data->imgs->blocked_exit = mlx_xpm_file_to_image(data->mlx, "./img/blocked_exit.xpm", &data->imgs->blocked_exit->width, &data->imgs->blocked_exit->height);
	data->imgs->collectible = mlx_xpm_file_to_image(data->mlx, "./img/collectible.xpm", &data->imgs->collectible->width, &data->imgs->collectible->height);
	data->imgs->player = mlx_xpm_file_to_image(data->mlx, "./img/player.xpm", &data->imgs->player->width, &data->imgs->player->height);
}

void destroy_images(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx, data->imgs->wall);
	mlx_destroy_image(data->mlx, data->imgs->floor);
	mlx_destroy_image(data->mlx, data->imgs->exit);
	mlx_destroy_image(data->mlx, data->imgs->blocked_exit);
	mlx_destroy_image(data->mlx, data->imgs->collectible);
	mlx_destroy_image(data->mlx, data->imgs->player);
}

int destroy_window(t_mlx_data *data)
{
	// destroy_images(data);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}
