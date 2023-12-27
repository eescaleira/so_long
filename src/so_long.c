/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:39:42 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/27 16:00:07 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int ac, char **av)
{
	t_mlx_data	data;

	data.map = malloc(sizeof(t_map));
	copy_map(&data.map->map_c, av[1]);
	check_map(&data, av[1]);

	innit_window(&data);
	if(!data.mlx || ac != 2)
		return (0);
	create_images(&data);
	create_map(&data);
	mlx_key_hook(data.mlx_win, handle_input, &data);
	mlx_hook(data.mlx_win, 17, 1L<<0, destroy_window, &data);

	mlx_loop(data.mlx);
}
