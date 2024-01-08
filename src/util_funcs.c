/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:13:17 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/08 19:15:46 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	open_map(char *map_name)
{
	int		fd;
	char	*file;

	file = ft_strjoin("maps/", map_name);
	fd = open(file, O_RDONLY);
	if (fd == 2)
		return (-1);
	free(file);
	return (fd);
}

int	copy_map(char ***map, char *map_name)
{
	int		i;
	int		fd;
	char	*line;
	char	**new_map;

	fd = open_map(map_name);
	if (fd == -1)
		return (-1);
	*map = NULL;
	line = get_next_line(fd);
	if (ft_strlen(line) <= 3)
		return (-1);
	while (line)
	{
		i = 0;
		while (*map != NULL && (*map)[i] != NULL)
			i++;
		new_map = (char **)malloc(sizeof(char *) * (i + 2));
		if (new_map == NULL)
			return (-1);
		write_map(map, new_map, line, i);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	check_map_chars(t_mlx_data *data, int i, int j)
{
	while (data->map->map_c[i] != NULL)
	{
		j = 0;
		while (data->map->map_c[i][j] != '\0')
		{
			if (check_char(data, i, j) == -1)
				return (-1);
			j++;
		}
		i++;
		data->map->width = j;
		data->map->height = i;
	}
	return (0);
}

void	put_block(t_mlx_data *data, int j, int i)
{
	if (data->map->map_c[i][j] == '1')
		put_wall(data, j, i);
	if (data->map->map_c[i][j] == '0')
		put_floor(data, j, i);
	if (data->map->map_c[i][j] == 'P')
		put_player(data, j, i);
	if (data->map->map_c[i][j] == 'C')
		put_collectible(data, j, i);
	if (data->map->map_c[i][j] == 'E')
	{
		if (data->map->collectibles == data->player->collectibles)
			put_exit(data, j, i);
		else
			put_floor(data, j, i);
	}
}
