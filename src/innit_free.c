/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:51:01 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/13 21:18:57 by eescalei         ###   ########.fr       */
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

int destroy_window(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}
