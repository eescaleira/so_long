/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:30:50 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/12 23:40:00 by eescalei         ###   ########.fr       */
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
	put_wall(data, 0, 0);
	return (0);
}

