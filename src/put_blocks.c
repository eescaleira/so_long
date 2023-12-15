/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_blocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:31:37 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/15 11:33:50 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void put_wall(t_mlx_data *data, t_image *imgs, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, imgs->wall, x, y);
}

void put_floor(t_mlx_data *data, t_image *imgs, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, imgs->floor, x, y);
}

void put_exit(t_mlx_data *data, t_image *imgs, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, imgs->exit, x, y);
}

void put_blocked_exit(t_mlx_data *data, t_image *imgs, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, imgs->blocked_exit, x, y);
}

void put_collectible(t_mlx_data *data, t_image *imgs, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, imgs->collectible, x, y);
}

void put_player(t_mlx_data *data, t_image *imgs, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, imgs->player, x, y);
}
