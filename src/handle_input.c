/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:30:50 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/16 14:59:28 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int handle_input(int keycode, t_mlx_data *data)
{
	
	if(keycode == XK_Escape || keycode == 17)
	{
		destroy_window(data);
		exit(0);
	}
	
	return (0);
}

