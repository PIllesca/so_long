/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:59:44 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/30 15:05:25 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_chk_char(char *str)
{
	int	c;
	int	s;

	c = 0;
	s = 0;
	while (*str)
	{
		if (*str != '0' && *str != '1' && *str != 'C'
			&& *str != 'E' && *str != 'P' && *str != '\n')
			return (ft_error_int("Carácter no válido en mapa", -1));
		if (*str == 'C')
			c++;
		if (*str == 'E' || *str == 'P')
			s++;
		str++;
	}
	if (s != 2 || c < 1)
		return (ft_error_int(
				"Necesario 1 entrada y salida y más de 1 coleccionable", -1));
	return (c);
}

static long int	ft_chk_xlen(char **map)
{
	size_t	len;

	len = ft_strlen(*map);
	while (*map != NULL)
	{
		if (len != ft_strlen(*map))
			return (ft_error_int("Error. Mapa no rectangular", -1));
		map++;
	}
	return (len);
}

static int	ft_chk_border(char **map, long int x_size)
{
	char		**tmp;
	long int	i;
	long int	y_size;

	tmp = map;
	while (*tmp)
		tmp++;
	y_size = tmp - map;
	i = 0;
	while (i < x_size)
	{
		if (map[0][i] != '1' || map[y_size - 1][i] != '1')
			return (ft_error_int("Borde no válido.",-1));
		i++;
	}
	i = 0;
	while (i < y_size)
	{
		if (map[i][0] != '1' || map[i][x_size - 1] != '1')
			return (ft_error_int("Borde no válido.",-1));
		i++;
	}
	return (y_size);
}

char	**ft_chk_map(char *str, long int *x_size, long int *y_size)
{
	char	**map;

	if (ft_chk_char(str) <= 0)
		return (NULL);
	map = ft_split(str, '\n');
	if (*map == NULL)
	{
		ft_printf("Error al leer el mapa");
		free(map);
		return (NULL);
	}
	*x_size = ft_chk_xlen(map);
	*y_size = ft_chk_border(map, *x_size);
	if (*x_size <= 0 || *y_size <= 0)
	{
		ft_printf("Mapa no válido\n");
		ft_free_map(map);
		return (NULL);
	}
	ft_printf("Tamaño x:%d y:%d", *x_size, *y_size);
	return (map);
}
