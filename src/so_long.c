/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:39:42 by eescalei          #+#    #+#             */
/*   Updated: 2023/11/23 00:30:40 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>

int main()
{
	void *mlx;
	void *mlx_win;	
	void *img;
	int x = 16, y = 16;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "first window");
	// img = mlx_xpm_file_to_image(mlx, "./assets/big_demon_idle_anim_f0.png", &x, &y);
	// mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	for(x = 0; x < 500; x++)
		for(y = 0; y < 500; y++)
			mlx_pixel_put(mlx, mlx_win, x, y, rand() % 0xFFFFFFFF);
					
	mlx_loop(mlx);
}