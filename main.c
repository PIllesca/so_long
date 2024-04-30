/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:26:15 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/30 23:05:25 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_mlx(char *str)
{
	t_data	data;

	data.map.map = ft_chk_map(str, &data.map.x, &data.map.y);
	free(str);
	if (data.map.map == NULL)
	{
		ft_printf("Mapa no leído\n");
		return ;
	}
	if (ft_chk_path(&data))
		error_exit(data);
	data.mlx = mlx_init(data.map.x * 16, data.map.y * 16, "My Game", true);
	if (!data.mlx)
		error_exit(data);
	init_player(&data);
	mlx_key_hook(data.mlx, ft_keyhook, &data);
	draw_map(data);
	draw_player(&data);
	draw_exit(data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	ft_free_map(data.map.map);
}

int	main(int argc, char **argv)
{
	char	*str;

	if (argc == 2)
		str = ft_read_map(argv[1]);
	else
		str = ft_read_map("maps/test.ber");
	if (str)
	{
		start_mlx(str);
	}
	return (0);
}
