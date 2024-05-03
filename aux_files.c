/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:58:12 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/03 16:57:23 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_free_null(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (str);
}

static char	*ft_read_file(int fd, char *buffer)
{
	size_t	size;
	char	*str;

	size = 1;
	while (size > 0)
	{
		str = ft_calloc(2, sizeof(char));
		if (!str)
			return (ft_free_null(buffer));
		size = read(fd, str, 2);
		if (size == 0)
		{
			free(str);
			break ;
		}
		str[size] = '\0';
		buffer = ft_strjoin_free(buffer, str);
	}
	if (size == 0 && *buffer == '\0')
		return (ft_free_null(buffer));
	return (buffer);
}

char	*ft_read_map(char *filename)
{
	int		fd;
	char	*buffer;

	fd = open(filename, 0);
	if (fd < 0 || read(fd, 0, 0) == -1)
	{
		ft_printf("Read Error\n");
		return (NULL);
	}
	buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
	{
		ft_printf("Read Error\n");
		return (NULL);
	}
	buffer = ft_read_file(fd, buffer);
	close(fd);
	return (buffer);
}
