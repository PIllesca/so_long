/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:26:40 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/30 13:07:55 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
#define SOLONG_H

#ifdef __linux__
    // Definiciones para Linux
    #define LIBRERIA_PATH "wslMLX42/MLX42.h"
#elif defined(__APPLE__)
    // Definiciones para macOS
    #define LIBRERIA_PATH "MLX42/MLX42.h"
#else
    #error "Sistema operativo no soportado"
#endif

#include LIBRERIA_PATH
#include <stdlib.h>
#include <fcntl.h>
#include "lib/ft_printf/ft_printf.h"

int     ft_error_int(char *str, int code);
char	*ft_read_map(char *filename);
void	error_exit(void	*mlx);
void	draw_map(void *mlx, char **map, size_t x_size, size_t y_size);
char	**ft_chk_map(char *str, long int *x_size, long int *y_size);
void	ft_free_map(char **map);

#endif /* SOLONG_H */