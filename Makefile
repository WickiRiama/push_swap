# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 16:38:50 by mriant            #+#    #+#              #
#    Updated: 2022/03/16 11:41:52 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

SRCS = ${addprefix srcs/, \
	insert_back.c \
	insert_in.c \
	main.c \
	parsing.c \
	push_swap.c \
	radix.c \
	set_move.c \
	sorting.c \
	test.c \
	utils.c}
BONUS_SRCS = ${addprefix srcs/, \
	main_bonus.c \
	parsing_args_bonus.c \
	parsing_ops_bonus.c \
	push_swap_bonus.c \
	utils_bonus.c \
	test.c}
GNL_SRCS = ${addprefix gnl/, \
	get_next_line.c \
	get_next_line_utils.c}

OBJS = ${patsubst srcs/%.c, build/%.o, ${SRCS}}
BONUS_OBJS = ${patsubst srcs/%.c, build/%.o, ${BONUS_SRCS}}
GNL_OBJS = ${patsubst gnl/%.c, build/%.o, ${GNL_SRCS}}

DEPS = ${patsubst srcs/%.c, build/%.d, ${SRCS}}
BONUS_DEPS = ${patsubst srcs/%.c, build/%.d, ${BONUS_SRCS}}
GNL_DEPS = ${patsubst gnl/%.c, build/%.d, ${GNL_SRCS}}

LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I./includes -I./libft -MMD
BONUS_IFLAGS = -I./gnl
LFLAGS = -Llibft -lft

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LFLAGS}

${LIBFT}:
	make -C libft

build/%.o: srcs/%.c
	@mkdir -p build
	${CC} ${CFLAGS} -c $< -o $@ ${IFLAGS} ${BONUS_IFLAGS}

build/%.o: gnl/%.c
	@mkdir -p build
	${CC} ${CFLAGS} -c $< -o $@ ${IFLAGS} ${BONUS_IFLAGS}

bonus: ${LIBFT} ${BONUS_OBJS} ${GNL_OBJS}
	${CC} ${CFLAGS} ${BONUS_OBJS} ${GNL_OBJS} -o ${BONUS_NAME} ${LFLAGS}

all: ${NAME}

clean:
	rm -rf ${OBJS} ${BONUS_OBJS} ${GNL_OBJS}
	rm -rf ${DEPS} ${BONUS_DEPS} ${GNL_DEPS}
	rm -rf build
	make -s -C libft clean

fclean: clean
	rm -rf ${NAME}
	rm -rf ${BONUS_NAME}
	make -s -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus

-include ${DEPS} ${BONUS_DEPS} ${GNL_DEPS}
