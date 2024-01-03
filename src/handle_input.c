/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:30:50 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/03 22:32:04 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_mlx_data *data)
{
	if (data->map->map_c[data->player->y - 1][data->player->x] != '1')
	{
		if (data->map->map_c[data->player->y - 1][data->player->x] == 'C')
			data->player->collectibles++;
		if (data->map->map_c[data->player->y - 1][data->player->x] == 'E')
			if (data->player->collectibles == data->map->collectibles)
				destroy_window(data);
		data->map->map_c[data->player->y][data->player->x] = '0';
		data->map->map_c[data->player->y - 1][data->player->x] = 'P';
		if (data->player->x == data->map->exit_x 
			&& data->player->y == data->map->exit_y)
			data->map->map_c[data->player->y][data->player->x] = 'E';
		data->player->y--;
		data->player->moves++;
		ft_printf("Total moves: %i\n", data->player->moves);
	}
}

void	move_down(t_mlx_data *data)
{
	if (data->map->map_c[data->player->y + 1][data->player->x] != '1')
	{
		if (data->map->map_c[data->player->y + 1][data->player->x] == 'C')
			data->player->collectibles++;
		if (data->map->map_c[data->player->y + 1][data->player->x] == 'E')
			if (data->player->collectibles == data->map->collectibles)
				destroy_window(data);
		data->map->map_c[data->player->y][data->player->x] = '0';
		data->map->map_c[data->player->y + 1][data->player->x] = 'P';
		if (data->player->x == data->map->exit_x 
			&& data->player->y == data->map->exit_y)
			data->map->map_c[data->player->y][data->player->x] = 'E';
		data->player->y++;
		data->player->moves++;
		ft_printf("Total moves: %i\n", data->player->moves);
	}
}

void	move_left(t_mlx_data *data)
{
	if (data->map->map_c[data->player->y][data->player->x - 1] != '1')
	{
		if (data->map->map_c[data->player->y][data->player->x - 1] == 'C')
			data->player->collectibles++;
		if (data->map->map_c[data->player->y][data->player->x - 1] == 'E')
			if (data->player->collectibles == data->map->collectibles)
				destroy_window(data);
		data->map->map_c[data->player->y][data->player->x] = '0';
		data->map->map_c[data->player->y][data->player->x - 1] = 'P';
		if (data->player->x == data->map->exit_x 
			&& data->player->y == data->map->exit_y)
			data->map->map_c[data->player->y][data->player->x] = 'E';
		data->player->x--;
		data->player->moves++;
		ft_printf("Total moves: %i\n", data->player->moves);
	}
}

void	move_right(t_mlx_data *data)
{
	if (data->map->map_c[data->player->y][data->player->x + 1] != '1')
	{
		if (data->map->map_c[data->player->y][data->player->x + 1] == 'C')
			data->player->collectibles++;
		if (data->map->map_c[data->player->y][data->player->x + 1] == 'E')
			if (data->player->collectibles == data->map->collectibles)
				destroy_window(data);
		data->map->map_c[data->player->y][data->player->x] = '0';
		data->map->map_c[data->player->y][data->player->x + 1] = 'P';
		if (data->player->x == data->map->exit_x 
			&& data->player->y == data->map->exit_y)
			data->map->map_c[data->player->y][data->player->x] = 'E';
		data->player->x++;
		data->player->moves++;
		ft_printf("Total moves: %i\n", data->player->moves);
	}
}

int	handle_input(int keycode, t_mlx_data *data)
{
	if (keycode == XK_Escape || keycode == 17)
		destroy_window(data);
	if (keycode == XK_w || keycode == XK_Up)
	{
		move_up(data);
		create_map(data);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		move_down(data);
		create_map(data);
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		move_left(data);
		create_map(data);
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		move_right(data);
		create_map(data);
	}
	return (0);
}
