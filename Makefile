# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 17:30:28 by heinfalt          #+#    #+#              #
#    Updated: 2017/01/14 17:02:29 by pbeller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re, all

.SUFFIXES:

NAME = fillit

SRC 	= fillit.c \
		checking.c \
		display.c \
		error.c \
		index.c \
		manip.c \
		map.c \
		read.c \
		reduce.c \
		remove_endl.c \
		solve.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a
LIBINC = -I ./libft
LIBLINK = -L ./libft -lft

all: $(NAME)

$(NAME) :
	make -C ./libft
	gcc $(CFLAGS) -c $(LIBINC) $(SRC)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBINC) $(LIBFT)

clean:
	make -C ./libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
