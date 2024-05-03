/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:26:15 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/03 17:21:16 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_steps(t_data *data)
{
	char			str[13];
	int				j;
	int				temp;
	int				n;
	unsigned int	num;

	n = data->steps;
	j = 0;
	if (n < 0)
		num = -n;
	else
		num = n;
	if (num == 0)
		str[j++] = '0';
	while (num != 0)
	{
		temp = num % 10;
		str[j++] = temp + '0';
		num /= 10;
	}
	if (n < 0)
		str[j++] = '-';
	str[j++] = '\0';
	ft_invstr(str);
	mlx_put_string(data->mlx, str, 0, 0);
}

static int	ft_chk_ext(char *str)
{
	size_t	len;
	char	*temp;

	len = ft_strlen(str);
	temp = str + len - 4;
	return (ft_strncmp(temp, ".ber", 4));
}

void	start_mlx(char *str)
{
	t_data	data;

	data.map.map = ft_chk_map(str, &data.map.x, &data.map.y);
	free(str);
	if (data.map.map == NULL)
	{
		ft_printf("Map wasn't read\n");
		return ;
	}
	if (ft_chk_path(&data))
		error_exit(&data);
	data.mlx = mlx_init(data.map.x * 16, data.map.y * 16, "My Game", true);
	if (!data.mlx)
		error_exit(&data);
	init_player(&data);
	mlx_key_hook(data.mlx, ft_keyhook, &data);
	draw_map(&data);
	draw_player(&data);
	draw_exit(&data);
	mlx_loop(data.mlx);
	success_exit(&data);
}

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	char	*str;

	atexit(ft_leaks);
	if (argc > 1)
	{
		if (ft_chk_ext(argv[1]) != 0)
		{
			ft_printf("Wrong file extension. Expected .ber\n");
			exit(EXIT_FAILURE);
		}
		str = ft_read_map(argv[1]);
	}
	else
	{
		ft_printf("A .ber map is needed\n");
		exit(EXIT_FAILURE);
	}
	if (str)
	{
		start_mlx(str);
	}
	return (0);
}
