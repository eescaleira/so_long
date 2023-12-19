/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:51:01 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/17 16:41:24 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void innit_window(t_mlx_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 500, 500, "first window");
}

void innit_img(void* mlx, t_data *img, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	img->img_pixels = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void create_images(t_mlx_data *data)
{
	data->imgs = malloc(sizeof(t_image));
	data->imgs->wall = malloc(sizeof(t_data));
	innit_img(data->mlx, data->imgs->wall, "./assets/wall.xpm");
	data->imgs->floor = malloc(sizeof(t_data));
	innit_img(data->mlx, data->imgs->floor, "./assets/floor.xpm");
	data->imgs->exit = malloc(sizeof(t_data));
	innit_img(data->mlx, data->imgs->exit, "./assets/exit.xpm");
	data->imgs->blocked_exit = malloc(sizeof(t_data));
	innit_img(data->mlx, data->imgs->blocked_exit, "./assets/blocked_exit.xpm");
	data->imgs->collectible = malloc(sizeof(t_data));
	innit_img(data->mlx, data->imgs->collectible, "./assets/collectible.xpm");
	data->imgs->player = malloc(sizeof(t_data));
	innit_img(data->mlx, data->imgs->player, "./assets/player.xpm");
}

void destroy_images(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx, data->imgs->wall->img);
	mlx_destroy_image(data->mlx, data->imgs->floor->img);
	mlx_destroy_image(data->mlx, data->imgs->exit->img);
	mlx_destroy_image(data->mlx, data->imgs->blocked_exit->img);
	mlx_destroy_image(data->mlx, data->imgs->collectible->img);
	mlx_destroy_image(data->mlx, data->imgs->player->img);
	free(data->imgs->wall);
	free(data->imgs->floor);
	free(data->imgs->exit);
	free(data->imgs->blocked_exit);
	free(data->imgs->collectible);
	free(data->imgs->player);
	free(data->imgs);
}

int destroy_window(t_mlx_data *data)
{
	destroy_images(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}
