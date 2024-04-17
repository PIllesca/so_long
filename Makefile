# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 18:46:03 by pillesca          #+#    #+#              #
#    Updated: 2024/04/17 19:55:41 by pillesca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c

INCLUDES = -I/MLX42

OBJ = $(SRC:.c=.o)

NAME = so_long.out

AR = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX42 = -LMLX42 -lMLX42 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

$(NAME): $(OBJ) ./MLX42/libmlx42.a
	$(CC) $(OBJ) $(CFLAGS) $(MLX42) -o $(NAME) 

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)