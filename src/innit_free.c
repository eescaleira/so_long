/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:51:01 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/15 11:49:56 by eescalei         ###   ########.fr       */
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

void create_images(t_mlx_data *data, t_image *imgs)
{
	imgs->wall = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &imgs->wall->width, &imgs->wall->height);
	imgs->floor = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm", &imgs->floor->width, &imgs->wall->height);
	imgs->exit = mlx_xpm_file_to_image(data->mlx, "./img/exit.xpm", &imgs->exit->width, &imgs->exit->height);
	imgs->blocked_exit = mlx_xpm_file_to_image(data->mlx, "./img/blocked_exit.xpm", &imgs->blocked_exit->width, &imgs->blocked_exit->height);
	imgs->collectible = mlx_xpm_file_to_image(data->mlx, "./img/collectible.xpm", &imgs->collectible->width, &imgs->collectible->height);
	imgs->player = mlx_xpm_file_to_image(data->mlx, "./img/player.xpm", &imgs->player->width, &imgs->player->height);
}

void destroy_images(t_mlx_data *data, t_image *imgs)
{
	mlx_destroy_image(data->mlx, imgs->wall);
	mlx_destroy_image(data->mlx, imgs->floor);
	mlx_destroy_image(data->mlx, imgs->exit);
	mlx_destroy_image(data->mlx, imgs->blocked_exit);
	mlx_destroy_image(data->mlx, imgs->collectible);
	mlx_destroy_image(data->mlx, imgs->player);
}

int destroy_window(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}
