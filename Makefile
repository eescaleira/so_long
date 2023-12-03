# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 14:59:22 by eescalei          #+#    #+#              #
#    Updated: 2023/12/03 19:19:04 by eescalei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra

SRC = src/so_long.c \
		src/innit_free.c \
		src/handle_input.c \
		src/render_funcs.c

OBJ = ${SRC:.c=.o}

all:	$(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -g -L./mlx -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)		

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all