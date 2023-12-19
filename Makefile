# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 14:59:22 by eescalei          #+#    #+#              #
#    Updated: 2023/12/18 19:32:39 by eescalei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra

SRC = src/so_long.c \
		src/innit_free.c \
		src/handle_input.c \
		src/put_blocks.c	\
		src/check_map.c \
		get_next_line/get_next_line_bonus.c \
		get_next_line/get_next_line_utils_bonus.c 

OBJ = ${SRC:.c=.o}

all:	$(NAME)

$(NAME): $(OBJ)
		make -C ./ft_printf/
		make -C ./libft/
		$(CC) $(FLAGS) $(OBJ) ./ft_printf/libftprintf.a ./libft/libft.a -g -L./mlx -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)		

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all