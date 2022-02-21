# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 16:38:50 by mriant            #+#    #+#              #
#    Updated: 2022/02/21 16:00:59 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ${addprefix srcs/, \
	main.c \
	parsing.c \
	push_swap.c \
	sorting.c \
	test.c \
	utils.c}
OBJS = ${patsubst srcs/%.c, build/%.o, ${SRCS}}
DEPS = ${patsubst srcs/%.c, build/%.d, ${SRCS}}

CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I./includes -I./libft -MMD
LFLAGS = -Llibft -lft

LIBFT = libft/libft.a

CC = cc

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LFLAGS}

${LIBFT}:
	make -s -C libft

build/%.o: srcs/%.c
	@mkdir -p build
	${CC} ${CFLAGS} -c $< -o $@ ${IFLAGS}

all: ${NAME}

clean:
	rm -rf ${OBJS} ${DEPS}
	rm -rf build
	make -s -C libft clean

fclean: clean
	rm -rf ${NAME}
	make -s -C libft fclean

re: fclean all

.PHONY: all clean fclean re

-include ${DEPS}
