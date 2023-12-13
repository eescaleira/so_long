/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:29:59 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/03 19:27:48 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	my_pixel_put_image(t_data *img, int x, int y, int color)
{
	int	dst;

	dst = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*((unsigned int*)(dst + img->img_pixels)) = color;
}

void color_screen(t_mlx_data *data, int color)
{
	int x = 1, y = 1;

	for(x = 0; x < 500; x++)
			for(y = 0; y < 500; y++)
				my_pixel_put_image(&data->img, x, y, color);
}