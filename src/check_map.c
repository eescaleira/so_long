/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:20:30 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/19 23:50:12 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void copy_map(char **map, char *map_name)
{
	int fd;
	char *temp;
	char *path;

	path = ft_strjoin("maps/", map_name);
	fd = open(ft_strjoin("maps/", map_name), O_RDONLY);
	if(fd <= 0)
	{
		ft_printf("Error openning file\n");
		exit(0);
	}
	// *map = get_next_line(fd);
	// if(map == NULL)
	// {
		// ft_printf("Error\n");
		// exit(0);
	// }
	// temp = *map;
	// while(map != NULL)
	// {
		// **map++;
		// *map = get_next_line(fd);
	// }
	// **map++;
	// *map = temp;
}