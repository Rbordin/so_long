# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 14:10:36 by rbordin           #+#    #+#              #
#    Updated: 2023/03/11 15:59:59 by riccardobor      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = ${NAME:.a=.h}

SOURCES = so_long.c	\
		control.c \
		get_next_line.c \
		get_next_line_utils.c \
		libft/ft_split.c \
		libft/ft_strjoin.c \
		libft/ft_strlen.c \
		libft/ft_substr.c \
		map.c \
		game.c \
		get_sprites.c \
		new_movement.c \
		player_loops.c \
		

OBJECTS = ${SOURCES:.c=.o}

MINILBX = minilibx_opengl_20191021
CC = gcc

OPTIONS = -c

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.o:.c
		${CC} ${CFLAGS} ${OBJECTS} $< -o ${<:.c=.o}

		
${NAME}: ${OBJECTS}
		${CC} ${OBJECTS} -Imlx -lmlx -framework OpenGl -framework AppKit

all: 	${NAME} ${MINILBX}

clean:
		${RM} ${OBJECTS}

fclean: 
		${RM} ${NAME}

re: fclean all
