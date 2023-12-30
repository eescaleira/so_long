/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:20:30 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/30 18:13:29 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void create_map(t_mlx_data *data)
{
    int i;
    int j;

    i = 0;
    while(data->map->map_c[i] != NULL)
    {
        j = 0;
        while(data->map->map_c[i][j] != '\0')
        {
            if(data->map->map_c[i][j] == '1')
                put_wall(data, j, i);
            if(data->map->map_c[i][j] == '0' || data->map->map_c[i][j] == 'P' 
            || data->map->map_c[i][j] == 'C' )
                put_floor(data, j, i);
            if(data->map->map_c[i][j] == 'P')
                put_player(data, j, i);
            if(data->map->map_c[i][j] == 'C')
                put_collectible(data, j, i);
            if(data->map->map_c[i][j] == 'E')
            {
                 if(data->map->collectibles == data->player->collectibles)
                    put_exit(data, j, i);
                else
                    put_blocked_exit(data, j, i);
            }
            j++;
        }
        i++;
    }
}

void check_map(t_mlx_data *data, char *map_name)
{
    int i;
    int j;
    int k;

    i = 0;
    k = 0;
    data->player = malloc(sizeof(t_player));
    data->player->collectibles = 0;
    data->map->collectibles = 0;
    while (data->map->map_c[i] != NULL)
    {
        j = 0;
        while(data->map->map_c[i][j] != '\0')
        {
            if (data->map->map_c[i][j] == 'P' )
            {
                data->player->x = j;
                data->player->y = i;
                k++;
            }
            if(data->map->map_c[i][j] == 'E')
            {
                data->map->exit_x = j;
                data->map->exit_y = i;
            }
            if (data->map->map_c[i][j] == 'C')
                data->map->collectibles++;
            j++;
        }
        i++;
    }
    data->map->width = j;
    data->map->height = i;
    if(!data->player->x || !data->map->exit_x/* flood_fill(data->map->map_c, data->player) */ )
        destroy_window(data); 
}
void copy_map(char ***map, char *map_name)
{
	int i;
    int fd;
    char **new_map;
	char *line;
    char *file;
    
    file = ft_strjoin("maps/", map_name);
    fd = open( file, O_RDONLY);
    if (fd <= 0)
    {
        ft_printf("Error opening file\n");
        exit(0);
    }
    free(file);
    *map = NULL;
    while((line = get_next_line(fd)))
    {
        i = 0;
        while(*map != NULL && (*map)[i] != NULL)
            i++;
        new_map = (char **)malloc(sizeof(char *) * (i + 2));
        if(new_map == NULL)
        {
            ft_printf("Memory allocation error\n");
            exit(0);
        }
        for(int j = 0; j < i; j++)
            new_map[j] = (*map)[j];
        new_map[i] = line;
        new_map[i + 1] = NULL;
        free(*map);
        *map = new_map;
    }
    close(fd);
}

void free_map(char **map)
{
    int i;

    i = 0;
    while(map[i] != NULL)
    {
        free(map[i]);
        i++;
    }
    free(map);
}
