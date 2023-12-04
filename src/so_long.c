/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:39:42 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/04 15:20:17 by eescalei         ###   ########.fr       */
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
	mlx_key_hook(data.mlx_win, handle_input, &data);
	
	mlx_loop(data.mlx);
	return (0);
}
