/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:30:50 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/03 18:30:36 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int handle_input(int keycode, t_mlx_data *data)
{
	
	if(keycode == XK_Escape)
	{
		destroy_window(data);
		exit(0);
	}
	else if(keycode == XK_a)
	{
		color_screen(data, 0xff00000);
	}
	else if(keycode == XK_w)
	{
		color_screen(data, 0x00ff000);
	}
	else if(keycode == XK_d)
	{
		color_screen(data, 0x0000ff);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	return (0);
}

