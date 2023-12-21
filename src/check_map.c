/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:20:30 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/21 17:13:56 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void copy_map(char ***map, char *map_name)
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
}