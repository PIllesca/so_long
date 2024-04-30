/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:54:51 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/30 23:48:20 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_data data, char c, int x, int y)
{
	mlx_texture_t	*t_tile;
	mlx_image_t		*i_tile;

	if (c == '1')
	{
		t_tile = mlx_load_png("./textures/sand.png");
		if (!t_tile)
			error_exit(data);
	}
	else
	{
		t_tile = mlx_load_png("./textures/water1.png");
		if (!t_tile)
			error_exit(data);
	}
	i_tile = mlx_texture_to_image(data.mlx, t_tile);
	if (!i_tile)
		error_exit(data);
	if (mlx_image_to_window(data.mlx, i_tile, x * 16, y * 16) < 0)
		error_exit(data);
}

static void	draw_collect(t_data data, int x, int y)
{
	mlx_texture_t	*t_coll;
	mlx_image_t		*i_coll;

	t_coll = mlx_load_png("./textures/Straw.png");
	if (!t_coll)
		error_exit(data);
	i_coll = mlx_texture_to_image(data.mlx, t_coll);
	if (!i_coll)
		error_exit(data);
	if (mlx_image_to_window(data.mlx, i_coll, x * 16, y * 16) < 0)
		error_exit(data);
}

void	draw_map(t_data data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data.map.y)
	{
		x = 0;
		while (x < data.map.x)
		{
			draw_tile(data, data.map.map[y][x], x, y);
			if (data.map.map[y][x] == 'c')
				draw_collect(data, x, y);
			x++;
		}
		y++;
	}
}

void	init_player(t_data *data)
{
	mlx_texture_t	*t_down;
	mlx_texture_t	*t_up;
	mlx_texture_t	*t_left;
	mlx_texture_t	*t_right;

	t_down = mlx_load_png("./textures/DolphinDown.png");
	t_up = mlx_load_png("./textures/DolphinUp.png");
	t_left = mlx_load_png("./textures/DolphinLeft.png");
	t_right = mlx_load_png("./textures/DolphinRight.png");
	if (!t_down || !t_left ||!t_right || !t_up)
		error_exit(*data);
	data->player.i_u = mlx_texture_to_image(data->mlx, t_up);
	data->player.i_d = mlx_texture_to_image(data->mlx, t_down);
	data->player.i_l = mlx_texture_to_image(data->mlx, t_left);
	data->player.i_r = mlx_texture_to_image(data->mlx, t_right);
	data->player.i_p = data->player.i_d;
	if (!data->player.i_u || !data->player.i_l
		|| !data->player.i_r || !data->player.i_u)
		error_exit(*data);
	draw_player(data);
}

void	draw_exit(t_data data)
{
	mlx_texture_t	*t_sprite;
	mlx_image_t		*i_sprite;

	if (data.c == data.map.c)
		t_sprite = mlx_load_png("./textures/CofferOpen.png");
	else
		t_sprite = mlx_load_png("./textures/Coffer.png");
	if (!t_sprite)
		error_exit(data);
	else
		i_sprite = mlx_texture_to_image(data.mlx, t_sprite);
	if (!i_sprite)
		error_exit(data);
	if (mlx_image_to_window(
			data.mlx, i_sprite, data.e_x * 16, data.e_y * 16) < 0)
		error_exit(data);
}
