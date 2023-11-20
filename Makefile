# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 14:59:22 by eescalei          #+#    #+#              #
#    Updated: 2023/11/20 17:48:19 by eescalei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra

SRC = src/so_long.c

OBJ = ${SRC:.c=.o}

all:	$(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -g -L./mlx -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)		

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all