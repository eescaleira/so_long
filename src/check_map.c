/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:20:30 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/08 19:16:11 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**dup_map(char **map, int i)
{
	int		j;
	char	**new_map;

	new_map = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
			j++;
		new_map[i] = (char *)malloc(sizeof(char) * (j + 1));
		j = 0;
		while (map[i][j] != '\0')
		{
			new_map[i][j] = map[i][j];
			j++;
		}
		new_map[i][j] = '\0';
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

int	create_map(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map_c[i] != NULL)
	{
		j = 0;
		while (data->map->map_c[i][j] != '\0')
		{
			put_block(data, j, i);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_map(t_mlx_data *data, char *map_name)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	data->player = malloc(sizeof(t_player));
	innit_variables(data);
	if (check_map_chars(data, i, j) == -1 || data->map->height < 3 
		|| data->map->width < 3)
		free_map_play(data);
	map = dup_map(data->map->map_c, data->map->height);
	if (check_walls(data->map) != 0 || !data->player->x || !data->map->exit_x 
		|| flood_fill(map, data->player->x, data->player->y, data->player))
	{
		free_map(map);
		free_map_play(data);
	}
	free_map(map);
	if (data->map->collectibles != data->player->collectibles)
		free_map_play(data);
	data->player->collectibles = 0;
}

int	check_walls(t_map *map)
{
	int	j;

	j = 0;
	while (map->map_c[j++ + 3] != NULL)
		if (ft_strlen(map->map_c[j]) != ft_strlen(map->map_c[j + 1]))
			return (1);
	if (ft_strlen(map->map_c[0]) != (ft_strlen(map->map_c[j + 1]) + 1))
		return (1);
	j = 0;
	while (map->map_c[0][j + 1] != '\0')
	{
		if (map->map_c[0][j] != '1')
			return (1);
		if (map->map_c[map->height -1][j] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (map->map_c[j + 1] != NULL)
	{
		if (map->map_c[j][0] != '1' || map->map_c[j][map->width - 1] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	flood_fill(char **map, int x, int y, t_player *player)
{
	if (map[y][x] == '1')
		return (1);
	if (map[y][x] == 'C')
		player->collectibles++;
	map[y][x] = '1';
	flood_fill(map, x + 1, y, player);
	flood_fill(map, x - 1, y, player);
	flood_fill(map, x, y + 1, player);
	flood_fill(map, x, y - 1, player);
	return (0);
}
