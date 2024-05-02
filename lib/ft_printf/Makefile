# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 11:16:21 by pillesca          #+#    #+#              #
#    Updated: 2024/04/12 11:40:33 by pillesca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_puthex.c aux_hex.c ft_put.c ft_printf.c 

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

AR = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
