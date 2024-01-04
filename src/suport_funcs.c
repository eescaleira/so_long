/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suport_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:13:35 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/04 18:16:28 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	write_map_c()
{
	int		j;
	int		i;
	char	**new_map;
	char	*line;

	j = 0;
	i = 0;
	while (*map != NULL && (*map)[i] != NULL)
		i++;
	new_map = (char **)malloc(sizeof(char *) * (i + 2));
	if (new_map == NULL)
		return (-1);
	while (j < i)
	{
		new_map[j] = (*map)[j];
		j++;
	}	
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(*map);
	*map = new_map;
	line = get_next_line(fd);

}