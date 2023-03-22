# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 15:14:35 by rbordin           #+#    #+#              #
#    Updated: 2023/03/16 16:52:31 by rbordin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ${NAME:.a=.h}

SOURCES = ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c\
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \

SOURCE_BONUS = ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \

OBJECTS = ${SOURCES:.c=.o}

OBJECT_BONUS = ${SOURCE_BONUS:.c=.o}

LIBC = ar rcs

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.o:.c
		@${CC} ${CFLAGS} ${OBJECTS} $< -o ${<:.c=.o}

${NAME}: ${OBJECTS}
		@${LIBC} ${NAME} ${OBJECTS}
		@ranlib ${NAME}

all: 	@${NAME}

clean:
		@${RM} ${OBJECTS} ${OBJECT_BONUS}

fclean: clean
		@${RM} ${NAME}

re: fclean all

bonus: @${OBJECTS} ${OBJECT_BONUS}
	   @${LIBC} ${NAME} ${OBJECTS} ${OBJECT_BONUS}
	   @ranlib ${NAME}
