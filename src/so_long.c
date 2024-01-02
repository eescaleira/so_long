/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:39:42 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/02 23:29:51 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// check if map is ber
// minimize problem 
//check map char 
// loop for em func 
int main(int ac, char **av)
{
	t_mlx_data	data;
	if(ac != 2 || check_ber(av[1]))
		return (0);
	data.map = malloc(sizeof(t_map));
	if(copy_map(&data.map->map_c, av[1]) == -1)
		destroy_window(&data);
	check_map(&data, av[1]);
	innit_window(&data);
	if(!data.mlx || ac != 2)
		destroy_window(&data);
	create_images(&data);
	create_map(&data);
	mlx_key_hook(data.mlx_win, handle_input, &data);
	mlx_hook(data.mlx_win, 17, 1L<<0, destroy_window, &data);
	mlx_loop(data.mlx);
}
