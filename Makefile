# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tauvray <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/17 11:01:12 by tauvray           #+#    #+#              #
#*   Updated: 2014/11/21 15:01:43 by tauvray          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# *********************************VARIABLES***********************************#

NAME = fractol

SRC_DIR = srcs/

SRC = srcs/main.c \
	  srcs/key_hook.c \
	  srcs/bresenham.c \
	  srcs/img_put.c \
	  srcs/julia.c \
	  srcs/mandelbroot.c \
	  srcs/tri_sierpinski.c \
	  srcs/mouse_hook.c \
	  srcs/color.c \
	  srcs/init_main.c \
	  srcs/ft_colors.c \

INC = includes/

LIBINC = libft/includes/

LIB = libft.a

BIN_DIR = bin/

BIN = main.o \
	  key_hook.o \
	  bresenham.o \
	  img_put.o \
	  julia.o \
	  mandelbroot.o \
	  tri_sierpinski.o \
	  mouse_hook.o \
	  color.o \
	  init_main.o \
	  ft_colors.o

CC = gcc

OPTS = -Wall -Werror -Wextra -L/usr/X11/lib -lmlx -lXext -lX11 -lm -g

# *********************************RULES***************************************#

all			: $(NAME)

$(NAME)		: 
	make -C libft/ fclean
	make -C libft/
	$(CC) $(OPTS) -I $(LIBINC) -I includes/ -c $(SRC)
	$(CC) $(OPTS) $(BIN) -L libft/ -lft -o $(NAME)

clean 		:
	make -C libft/ clean
	rm -f $(BIN)

fclean		: clean
	make -C libft/ fclean
	rm -f $(NAME)

re			: fclean all 
