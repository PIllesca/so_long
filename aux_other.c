/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:35:06 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/30 13:05:29 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_int(char *str, int code)
{
	ft_printf("%s\n", str);
	return (code);
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
