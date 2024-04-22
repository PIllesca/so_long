/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:26:40 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/22 12:36:15 by pillesca         ###   ########.fr       */
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
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#endif /* SOLONG_H */