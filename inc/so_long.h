/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:29:36 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/01 17:31:27 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"
#include <stdio.h>
#include <stdlib.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

typedef struct	s_mlx_data{
	void	*mlx;
	void	*mlx_win;
}				t_mlx_data;

/* handle input */
int handle_input(int keycode, t_mlx_data *data);

/* frees */
void destroy_window(t_mlx_data *mlx_data);

#endif