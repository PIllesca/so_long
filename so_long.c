/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:54:51 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/29 19:54:04 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(void	*mlx)
{
	if (mlx)
		mlx_terminate(mlx);
	exit(EXIT_FAILURE);
}

static void	draw_tile(void *mlx, char c, int x, int y)
{
	mlx_texture_t	*t_tile;
	mlx_image_t		*i_tile;

	if (c == '1')
	{
		t_tile = mlx_load_png("./textures/sand.png");
		if (!t_tile)
			error_exit(mlx);
	}
	else
	{
		t_tile = mlx_load_png("./textures/water1.png");
		if (!t_tile)
			error_exit(mlx);
	}
	i_tile = mlx_texture_to_image(mlx, t_tile);
	if (!i_tile)
		error_exit(mlx);
	if (mlx_image_to_window(mlx, i_tile, x * 16, y * 16) < 0)
		error_exit(mlx);
}

void	draw_map(void *mlx, char **map, size_t x_size, size_t y_size)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < y_size)
	{
		x = 0;
		while (x < x_size)
		{
			draw_tile(mlx, map[y][x], x, y);
			x++;
		}
		y++;
	}
}
