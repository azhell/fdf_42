# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 14:43:45 by yalytvyn          #+#    #+#              #
#    Updated: 2020/01/11 12:06:38 by yalytvyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC		= src/main.c \
		  src/key.c \
		  src/draw.c \
		  src/error.c \
		  src/color.c \
		  src/read_map.c \
		  src/valid.c \
		  src/utils.c \
		  src/utils2.c \
		  src/list.c \
		  src/projection.c

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror -L libft/ -lft -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME) -Iinclude -Ilibft/includes -o $(NAME)

clean:
	/bin/rm -rf obj/
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

	gcc -Wall -Wextra -Werror -L libft/ -lft -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME) -Iinclude -Ilibft/includes -o $(NAME)
