# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 14:10:36 by rbordin           #+#    #+#              #
#    Updated: 2023/03/20 17:12:05 by rbordin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MINILIBX_PATH = ./mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a
P1 = gnl/
HEADER = ${NAME:.a=.h}

SOURCES = so_long.c	\
		control.c \
		$(P1)get_next_line.c \
		$(P1)get_next_line_utils.c \
		map.c \
		game.c \
		get_sprites.c \
		new_movement.c \
		time.c \
		movement_utils.c \
		map_utils.c \
		

OBJECTS = ${SOURCES:.c=.o}

MLX = ./libmlx.dylib
CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -g

.o:.c
		${CC} ${CFLAGS} -Imlx -c $< -o $@
		
all: 	${NAME}

${NAME}: ${OBJECTS} $(LIBFT)
		${CC} ${OBJECTS} $(LIBFT) -Lmlx -lmlx -framework OpenGl -framework AppKit -o ${NAME}

$(MINILIBX):
			make -C $(MINILIBX_PATH)
			
$(LIBFT) : 
			make -C $(LIBFT_PATH)

clean:
		${RM} ${OBJECTS} 
		rm -f gnl/*.o
		make clean -C $(LIBFT_PATH)
		make clean -C $(MINILIBX_PATH)

fclean: clean
		${RM} $(LIBFT)
		${RM} ${NAME}
		${RM} $(MINILIBX)

re: fclean all
