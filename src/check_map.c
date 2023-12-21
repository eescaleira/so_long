/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:20:30 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/21 18:30:29 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void copy_map(char ***map, char *map_name)
{
	int i;
    int fd;
    char **new_map;
	char *line;

    fd = open(ft_strjoin("maps/", map_name), O_RDONLY);
    if (fd <= 0)
    {
        ft_printf("Error opening file\n");
        exit(0);
    }
    *map = NULL;
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
    }
	ft_printf("map: %s\n", (*map)[1]);
    close(fd);
}

