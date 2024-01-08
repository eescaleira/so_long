/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:28:30 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/08 19:16:41 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

void	destroy_images(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx, data->imgs->wall->img);
	mlx_destroy_image(data->mlx, data->imgs->floor->img);
	mlx_destroy_image(data->mlx, data->imgs->exit->img);
	mlx_destroy_image(data->mlx, data->imgs->blocked_exit->img);
	mlx_destroy_image(data->mlx, data->imgs->collectible->img);
	mlx_destroy_image(data->mlx, data->imgs->player->img);
	free(data->imgs->wall);
	free(data->imgs->floor);
	free(data->imgs->exit);
	free(data->imgs->blocked_exit);
	free(data->imgs->collectible);
	free(data->imgs->player);
	free(data->imgs);
}

int	destroy_window(t_mlx_data *data)
{
	if (data->imgs)
		destroy_images(data);
	if (data->map)
	{
		free(data->player);
		free_map(data->map->map_c);
		free(data->map);
	}
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit (0);
}

void	free_map_play(t_mlx_data *data)
{
	free(data->player);
	free_map(data->map->map_c);
	free(data->map);
	exit (0);
}
