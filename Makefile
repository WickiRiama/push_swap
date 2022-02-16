# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 16:38:50 by mriant            #+#    #+#              #
#    Updated: 2022/02/16 17:37:50 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ${addprefix srcs/, \
	ops.c \
	parsing.c \
	push_swap.c}
OBJS = ${patsubst srcs/%.c, objs/%.o, ${SRCS}}
DEPS = ${patsubst srcs/%.c, deps/%.d, ${SRCS}}

CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I./includes -I./libft -MMD
LFLAGS = -Llibft -lft

LIBFT = libft/libft.a

CC = cc

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LFLAGS}

${LIBFT}:
	make -s -C libft

objs/%.o: srcs/%.c
	@mkdir -p objs
	@mkdir -p deps
	${CC} ${CFLAGS} -c $< -o $@ ${IFLAGS}

all: ${NAME}

clean:
	rm -rf ${OBJS} ${DEPS}
	rm -rf objs deps
	make -s -C libft clean

fclean: clean
	rm -rf ${NAME}
	make -s -C libft fclean

re: fclean all

.PHONY: all clean fclean re

-include ${DEPS}