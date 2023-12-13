/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:39:42 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/13 16:51:54 by eescalei         ###   ########.fr       */
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
	
	put_wall(&data, 0, 0);
	
	mlx_key_hook(data.mlx_win, handle_input, &data);
	mlx_hook(data.mlx_win, 17, 1L<<0, destroy_window, &data);
	
	mlx_loop(data.mlx);
}
