/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:45:29 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/01 15:27:25 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_data *data)
{
	if (mlx_image_to_window(
			data->mlx, data->player.i_p, data->player.x * 16,
			data->player.y * 16) < 0)
		error_exit(*data);
}

static int	ft_exit(t_data *data)
{
	ft_printf("Cerrando. Pasos: %d\n", data->steps);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	ft_free_map(data->map.map);
	exit(EXIT_SUCCESS);
}

static void	ft_chk_pos(t_data *data)
{
	if (data->map.map[data->player.y][data->player.x] == 'c')
	{
		data->c++;
		data->map.map[data->player.y][data->player.x] = '0';
		ft_printf("Colleccionables: %d ", data->c);
		ft_printf("restantes: %d\n", data->map.c - data->c);
		draw_exit(*data);
	}
	if (data->map.map[data->player.y][data->player.x] == 'E'
		&& data->c == data->map.c)
	{
		ft_printf("¡Ganaste! ");
		ft_exit(data);
	}
}

static void	ft_move_player(t_data *data, int x, int y, char c)
{
	draw_tile(*data, '0', data->player.x, data->player.y);
	data->steps++;
	ft_printf("Pasos: %d\n", data->steps);
	draw_tile(*data, '1', 0, 0);
	draw_tile(*data, '1', 1, 0);
	ft_print_steps(data);
	if (data->map.map[data->player.y][data->player.x] == 'E')
		draw_exit(*data);
	if (c == 'w')
		data->player.i_p = data->player.i_u;
	if (c == 's')
		data->player.i_p = data->player.i_d;
	if (c == 'a')
		data->player.i_p = data->player.i_l;
	if (c == 'd')
		data->player.i_p = data->player.i_r;
	if (data->map.map[data->player.y + y][data->player.x + x] != '1')
	{
		data->player.x += x;
		data->player.y += y;
		ft_chk_pos(data);
	}
	draw_player(data);
}

void	ft_keyhook(mlx_key_data_t key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key.key == MLX_KEY_ESCAPE)
	{
		ft_exit(data);
	}
	else
	{
		if (key.action != MLX_RELEASE)
		{
			if (key.key == MLX_KEY_A)
				ft_move_player(data, -1, 0, 'a');
			if (key.key == MLX_KEY_W)
				ft_move_player(data, 0, -1, 'w');
			if (key.key == MLX_KEY_S)
				ft_move_player(data, 0, 1, 's');
			if (key.key == MLX_KEY_D)
				ft_move_player(data, 1, 0, 'd');
		}
	}
}
