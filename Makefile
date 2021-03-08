# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masboula <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 16:06:54 by masboula          #+#    #+#              #
#    Updated: 2021/02/24 16:07:14 by masboula         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRCS = 	main.c mlx_errors.c init.c bmp_save.c \
		parsing/get_coord.c \
		parsing/check_valid.c \
        parsing/parse_map.c \
		parsing/open_cub.c \
        parsing/get_text.c \
		parsing/check_content.c \
        mini_map/custom_map.c \
		useful.c \
		raycasting/sprite_pos.c \
		raycasting/raycasting_sprite.c \
		raycasting/put_tex_on.c \
		raycasting/raycasting_tex.c \
		raycasting/move.c \
		raycasting/keys.c \
		raycasting/steps.c \
        gnl/get_next_line.c \
        gnl/get_next_line_utils.c \

MLX_PATH	=	minilibx/
MLX_NAME	=	${MLX_PATH}libmlx_Linux.a
MLX_I		=	-I${MLX_PATH}

LIBC_PATH	=	libft/
LIBC_NAME	=	${LIBC_PATH}libft.a
LIBC_I	=	-I${LIBC_PATH}

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIB = ar -rc ${NAME}

.o.c = $(CC) ${CFLAGS} -c $< -o ${$<.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	@make --silent -C libft/
	@make --silent -C minilibx/
	@${CC} ${OBJS} ${MLX_NAME} ${LIBC_NAME} -L${MLX_PATH} -L/usr/lib -L${LIBC_PATH} ${LIBC_I} ${MLX_INC} -lXext -lX11 -lm -o ${NAME}

clean:
	@make clean --silent -C libft/
	@make clean --silent -C minilibx/
	${RM} ${OBJS}

fclean: clean
	@make fclean --silent -C libft/
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
