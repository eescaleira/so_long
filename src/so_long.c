/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:39:42 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/01 17:44:06 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main()
{
	t_mlx_data	*data;
	int x = 16, y = 16;
	data = malloc(sizeof(t_mlx_data));
	data->mlx = mlx_init();
	if(!data->mlx)
		return (0);
	data->mlx_win = mlx_new_window(data->mlx, 500, 500, "first window");
	mlx_key_hook(data->mlx_win, handle_input, data);
	mlx_loop(data->mlx);
	return (0);
}

	// for(x = 0; x < 500; x++)
	// 	for(y = 0; y < 500; y++)
	// 		mlx_pixel_put(data->mlx, data->mlx_win, x, y, rand() % 0xFFFFFFFF);