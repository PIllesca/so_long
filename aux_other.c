/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:35:06 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/30 23:05:01 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_int(char *str, int code)
{
	ft_printf("%s\n", str);
	return (code);
}

void	error_exit(t_data data)
{
	if (data.mlx)
		mlx_terminate(data.mlx);
	if (data.map.map)
		ft_free_map(data.map.map);
	exit(EXIT_FAILURE);
}

void	ft_free_map(char **map)
{
	char	**temp;

	temp = map;
	while (*temp != NULL)
	{
		free(*temp);
		temp++;
	}
	free(map);
}
