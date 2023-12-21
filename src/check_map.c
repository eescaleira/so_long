/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:20:30 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/21 17:56:06 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void write_map(char ***map, int fd)
{
	char *line;	
	char **new_map;
	int i;

	while ((line = get_next_line(fd)))
    {
        i = 0;
        while (*map != NULL && (*map)[i] != NULL)
            i++;
        new_map = (char **)malloc(sizeof(char *) * (i + 2));
        if (new_map == NULL)
        {
            ft_printf("Memory allocation error\n");
            exit(0);
        }
        for (int j = 0; j < i; j++)
            new_map[j] = (*map)[j];
        new_map[i] = line;
        new_map[i + 1] = NULL;
        free(*map);
        *map = new_map;
		free(line);
    }
}

void copy_map(char ***map, char *map_name)
{
    int fd;
	char *path;

	path = ft_strjoin("maps/", map_name);
    fd = open(path, O_RDONLY);
	free(path);
    if (fd <= 0)
    {
        ft_printf("Error opening file\n");
        exit(0);
    }
    *map = NULL;
	write_map(map, fd);
	ft_printf("map: %s\n", **map);
    close(fd);
}

