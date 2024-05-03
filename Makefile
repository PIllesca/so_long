# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 18:46:03 by pillesca          #+#    #+#              #
#    Updated: 2024/05/03 14:09:22 by pillesca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I/MLX42/include
MLX42 = ./MLX42/libmlx42.a -LMLX42 -lMLX42 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

PRINTSRC = libftprintf.a
PRINTDIR = ./lib/ft_printf
LIBFTSRC = libft.a
LIBFTDIR = ./lib/libft

SRC = so_long.c aux_files.c aux_map.c aux_other.c aux_path.c key_hook.c main.c

OBJ = $(SRC:.c=.o)

NAME = so_long

AR = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: makelib $(NAME)

makelib:
	make -C $(PRINTDIR)
	make -C $(LIBFTDIR)

$(NAME): $(OBJ) 
	$(CC) $(OBJ) $(CFLAGS) $(PRINTDIR)/$(PRINTSRC) $(LIBFTDIR)/$(LIBFTSRC) $(MLX42) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(PRINTDIR)
	make clean -C $(LIBFTDIR)
	
fclean: clean
	$(RM) $(NAME)
	$(RM) $(PRINTSRC)
	$(RM) $(LIBFTSRC)

re:	fclean all

.PHONY: all, clean, fclean