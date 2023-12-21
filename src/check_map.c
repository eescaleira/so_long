/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:20:30 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/21 17:28:47 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* void copy_map(char ***map, char *map_name)
{
	int fd;
	int i;
	char *line;
	char *path;

	i = 0;
	path = ft_strjoin("maps/", map_name);
	fd = open(ft_strjoin("maps/", map_name), O_RDONLY);
	if(fd <= 0)
	{
		ft_printf("Error openning file\n");
		exit(0);
	}
	// ft_printf("%s", get_next_line(fd));
	// ft_printf("%s", get_next_line(fd));
	// ft_printf("%s", get_next_line(fd));
	while(line = get_next_line(fd))
	{
		*map = &line;	
		**map++;
		ft_printf("map: %s\n", **map);
	}
	// temp = *map;
	// while(map != NULL)
	// {
		// **map++;
		// *map = get_next_line(fd);
	// }
	// **map++;
	// *map = temp;
} */

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

    // Initialize an empty list for the map
    *map = NULL;

    while ((line = get_next_line(fd)))
    {
        i = 0;

        // Calculate the current size of the map
        while (*map != NULL && (*map)[i] != NULL)
            i++;

        // Allocate memory for the new map with one additional element
        new_map = (char **)malloc(sizeof(char *) * (i + 2));

        if (new_map == NULL)
        {
            ft_printf("Memory allocation error\n");
            exit(0);
        }

        // Copy existing lines to the new map
        for (int j = 0; j < i; j++)
            new_map[j] = (*map)[j];

        // Append the new line
        new_map[i] = line;
        new_map[i + 1] = NULL;

        // Free the old map
        free(*map);

        // Update the map pointer to the new map
        *map = new_map;
    }
	ft_printf("map: %s\n", **map);
    close(fd);
}

