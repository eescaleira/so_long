/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_blocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:31:37 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/03 22:43:01 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_wall(t_mlx_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->imgs->wall->img, x * 32, y * 32);
}

void	put_floor(t_mlx_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->imgs->floor->img, x * 32, y * 32);
}

void	put_exit(t_mlx_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->imgs->exit->img, x * 32, y * 32);
}

void	put_collectible(t_mlx_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->imgs->collectible->img, x * 32, y * 32);
}

void	put_player(t_mlx_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->imgs->player->img, x * 32, y * 32);
}
