/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_blocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:31:37 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/12 23:43:25 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void put_wall(t_mlx_data *data, int x, int y)
{
	data->img.img = mlx_xpm_file_to_image(data->mlx, "./assets/wall.xpm", &data->img.width, &data->img.height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
}

void put_floor(t_mlx_data *data, int x, int y)
{
	data->img.img = mlx_xpm_file_to_image(data->mlx, "./assets/floor.xpm", &data->img.width, &data->img.height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
}

void put_exit(t_mlx_data *data, int x, int y)
{
	data->img.img = mlx_xpm_file_to_image(data->mlx, "./assets/exit.xpm", &data->img.width, &data->img.height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
}

void put_blocked_exit(t_mlx_data *data, int x, int y)
{
	data->img.img = mlx_xpm_file_to_image(data->mlx, "./assets/blocked_exit.xpm", &data->img.width, &data->img.height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
}

void put_collectible(t_mlx_data *data, int x, int y)
{
	data->img.img = mlx_xpm_file_to_image(data->mlx, "./assets/collectible.xpm", &data->img.width, &data->img.height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
}

void put_player(t_mlx_data *data, int x, int y)
{
	data->img.img = mlx_xpm_file_to_image(data->mlx, "./assets/player.xpm", &data->img.width, &data->img.height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
}

void put_enemy(t_mlx_data *data, int x, int y)
{
	data->img.img = mlx_xpm_file_to_image(data->mlx, "./assets/enemy.xpm", &data->img.width, &data->img.height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, x, y);
}