/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:54:51 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/17 20:05:01 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include <stdlib.h>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int	main(void)
{
	void	*mlx;

	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "My Game", true);
	if (!mlx)
		return (1);
	mlx_loop(mlx);
	free (mlx);
	return (0);
}
