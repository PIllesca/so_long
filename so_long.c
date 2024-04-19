/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:54:51 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/19 12:56:29 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(void	*mlx)
{
	if (mlx)
		mlx_terminate(mlx);
	exit(EXIT_FAILURE);
}

static void	draw_texture(void *mlx)
{
	mlx_texture_t	*t_sand;
	mlx_image_t		*i_sand;

	t_sand = mlx_load_png("./textures/sand.png");
	if (!t_sand)
		error_exit(mlx);
	i_sand = mlx_texture_to_image(mlx, t_sand);
	if (!i_sand)
		error_exit(mlx);
	if (mlx_image_to_window(mlx, i_sand, 0, 0) < 0)
		error_exit(mlx);
}

int	main(void)
{
	void	*mlx;

	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "My Game", true);
	if (!mlx)
		error_exit(mlx);
	draw_texture(mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
