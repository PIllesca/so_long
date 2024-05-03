/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:11:31 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/03 16:51:35 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_find_start(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->map.c = 0;
	data->steps = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			if (data->map.map[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
			}
			if (data->map.map[y][x] == 'C')
				data->map.c++;
			x++;
		}
		y++;
	}
}

static bool	ft_chk_valid(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == '0' || data->map.map[y][x] == 'E' ||
		data->map.map[y][x] == 'C' || data->map.map[y][x] == 'P')
		return (true);
	else
		return (false);
}

static void	ft_dfs(t_data *data, int x, int y, bool *valid)
{
	if (data->map.map[y][x] == 'E')
	{
		*valid = true;
		data->e_x = x;
		data->e_y = y;
	}
	else if (data->map.map[y][x] == 'C')
	{
		data->map.map[y][x] = 'c';
		data->c--;
	}
	else
		data->map.map[y][x] = 'V';
	if (ft_chk_valid(data, x + 1, y))
		ft_dfs(data, x + 1, y, valid);
	if (ft_chk_valid(data, x - 1, y))
		ft_dfs(data, x - 1, y, valid);
	if (ft_chk_valid(data, x, y + 1))
		ft_dfs(data, x, y + 1, valid);
	if (ft_chk_valid(data, x, y - 1))
		ft_dfs(data, x, y - 1, valid);
}

void	ft_text_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			x++;
		}
		y++;
	}
}

int	ft_chk_path(t_data *data)
{
	bool	valid;

	valid = false;
	ft_find_start(data);
	data->c = data->map.c;
	ft_text_map(data);
	ft_dfs(data, data->player.x, data->player.y, &valid);
	if (valid && data->c != 0)
	{
		ft_printf("Invalid path.\n");
		return (1);
	}
	return (0);
}
