#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jucapik <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 13:09:58 by jucapik           #+#    #+#              #
#    Updated: 2019/04/19 14:40:44 by jucapik          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fdf

CC			=	gcc

CFLAGS		+=	-Wall -Wextra -Werror

SRC0		=	main.c	data.c img.c position.c matrice.c key_press.c \
				key_press2.c lines.c key_press3.c matrice2.c free.c data2.c

SRCPATH0	=	.

SOURCES0	=	$(addprefix $(SRCPATH0)/, $(SRC0))

HDR0		=	fdf.h


HDRPATH0	=	.

HEADERS0	=	$(addprefix $(HDRPATH0)/, $(HDR0))

MLXNAME		=	mlx

ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS), Darwin)
	MLXPATH		=	./minilibx_macos

	MLXHEAD		=	./minilibx_macos
else
	MLXPATH		=	./minilibx_linux

	MLXHEAD		=	./minilibx_linux
endif

LIBNAME		=	ft

LIBPATH		=	libft

LIBHEAD		=	libft

OBJ0		=	$(SRC0:.c=.o)

%.o:		$(SRCPATH0)/%.c
	$(CC) -o $@ -c $^ $(CFLAGS)

.PHONY:		clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ0) $(HDRPATH0)/$(HDR0)
	cd $(MLXPATH) && $(MAKE)
	cd $(LIBPATH) && $(MAKE)
	$(CC) -o $(NAME) $(OBJ0) -I $(LIBHEAD) -L $(LIBPATH) -l$(LIBNAME) \
		-I $(MLXHEAD) -L $(MLXPATH) -l$(MLXNAME) \
		-lmlx -framework OpenGL -framework AppKit


clean:
	cd $(LIBPATH) && $(MAKE) clean
	cd $(MLXPATH) && $(MAKE) clean
	rm -rf $(OBJ0)

fclean:
	cd $(LIBPATH) && $(MAKE) fclean
	cd $(MLXPATH) && $(MAKE) clean
	rm -rf $(OBJ0)
	rm -rf $(NAME)

re:			fclean all
