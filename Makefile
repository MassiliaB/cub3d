NAME = Cub3D

SRCS = main.c custom_map.c mlx_errors.c parse_map.c open_cub.c get_coord.c \
	check_content.c view.c player_map.c keys.c scene.c ft_move.c\
	init.c get_text.c textures_gen.c  check_valid.c\
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

CFLAGS = -g3

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
