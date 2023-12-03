/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:39:42 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/03 19:25:05 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main()
{
	t_mlx_data	data;

	innit_window(&data);
	if(!data.mlx)
		return (0);
	innit_img(&data);
	data.img.img = mlx_new_image(data.mlx, 500, 500);
	data.img.img_pixels = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	
	mlx_key_hook(data.mlx_win, handle_input, &data);
	
	mlx_loop(data.mlx);
	return (0);
}
