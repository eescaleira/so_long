/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suport_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:13:35 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/08 19:12:08 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	write_map(char ***map, char **new_map, char *line, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		new_map[j] = (*map)[j];
		j++;
	}
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(*map);
	*map = new_map;
}

int	check_char(t_mlx_data *data, int i, int j)
{
	if (data->map->map_c[i][j] == 'P' )
	{
		if (data->player->x != -1)
			return (-1);
		data->player->x = j;
		data->player->y = i;
	}
	else if (data->map->map_c[i][j] == 'E')
	{
		if (data->map->exit_x != -1)
			return (-1);
		data->map->exit_x = j;
		data->map->exit_y = i;
	}
	else if (data->map->map_c[i][j] == 'C')
		data->map->collectibles++;
	else if (data->map->map_c[i][j] != '0' 
		&& data->map->map_c[i][j] != '1' 
		&& data->map->map_c[i][j] != '\n')
		return (-1);
	return (0);
}
