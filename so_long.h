/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:26:40 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/02 17:56:03 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __linux__
#  include "wslMLX42/MLX42.h"
# else
#  include "MLX42/MLX42.h"
# endif

# include <stdlib.h>
# include <fcntl.h>
# include "lib/ft_printf/ft_printf.h"
# include "lib/libft/libft.h"

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		c;
}			t_map;

typedef struct s_play
{
	int				x;
	int				y;
	mlx_image_t		*i_p;
	mlx_image_t		*i_u;
	mlx_image_t		*i_d;
	mlx_image_t		*i_l;
	mlx_image_t		*i_r;
}			t_play;

typedef struct s_data
{
	void	*mlx;
	int		e_x;
	int		e_y;
	int		steps;
	int		c;
	t_map	map;
	t_play	player;
}				t_data;

int		ft_error_int(char *str, int code);
char	*ft_read_map(char *filename);
void	error_exit(t_data data);
void	draw_tile(t_data data, char c, int x, int y);
void	draw_map(t_data data);
void	init_player(t_data *data);
void	draw_player(t_data *data);
void	draw_exit(t_data data);
char	**ft_chk_map(char *str, int *x_size, int *y_size);
int		ft_chk_path(t_data *data);
void	ft_free_map(char **map);
void	ft_keyhook(mlx_key_data_t key, void *param);
void	ft_print_steps(t_data *data);

#endif /* SOLONG_H */