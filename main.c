/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:26:15 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/30 13:10:40 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_mlx(char *str)
{
	void		*mlx;
	char		**map;
	long int	x;
	long int	y;

	map = ft_chk_map(str, &x, &y);
	free(str);
	if (map == NULL)
	{
		ft_printf("Mapa no leído\n");
		return ;
	}
	mlx = mlx_init(x * 16, y * 16, "My Game", true);
	if (!mlx)
		error_exit(mlx);
	draw_map(mlx, map, x, y);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	ft_free_map(map);
}

int	main(void)
{
	char	*str;

	str = ft_read_map("maps/test.ber");
	if (str)
	{
		start_mlx(str);
	}
	return (0);
}
