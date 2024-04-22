# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 18:46:03 by pillesca          #+#    #+#              #
#    Updated: 2024/04/22 15:50:06 by pillesca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Detectar el sistema operativo
ifeq ($(shell uname), Linux)
    OS := linux
else ifeq ($(shell uname), Darwin)
    OS := macos
else
    $(error Sistema operativo no soportado: $(shell uname))
endif

# Directorios y configuraciones según el sistema operativo
ifeq ($(OS), linux)
    INCLUDES = -I/wslMLX42/include
	MLX42 = ./wslMLX42/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
else ifeq ($(OS), macos)
    INCLUDES = -I/MLX42/include
	MLX42 = ./MLX42/libmlx42.a -LMLX42 -lMLX42 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
endif

SRC = so_long.c

OBJ = $(SRC:.c=.o)

NAME = so_long.out

AR = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(OBJ) $(CFLAGS) $(MLX42) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

.PHONY: all, clean, fclean