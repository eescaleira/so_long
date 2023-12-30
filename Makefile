# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 14:59:22 by eescalei          #+#    #+#              #
#    Updated: 2023/12/28 18:31:48 by eescalei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra

SRC = src/so_long.c \
		src/innit_free.c \
		src/handle_input.c \
		src/put_blocks.c	\
		src/check_map.c 

OBJ = ${SRC:.c=.o}

all:	$(NAME)

$(NAME): $(OBJ) 
	make -C ./my_library/
	$(CC) $(FLAGS) $(OBJ)  ./my_library/get_next_line/get_next_line.a ./my_library/ft_printf/libftprintf.a ./my_library/libft/libft.a -g -L./mlx -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)		

clean:
	rm -f $(OBJ)
	make fclean -C ./my_library/

fclean: clean
	rm -f $(NAME)

re: fclean all
.SILENT: