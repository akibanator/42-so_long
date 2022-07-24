NAME =			so_long
CC =			gcc
FLAGS =			-Wall -Wextra -Werror
RM =			/bin/rm -f
LIBMLX_FLAGS =	-lmlx -lXext -lX11
LIB_PATH =		lib/printf
LIB =			$(LIB_PATH)/libftprintf.a

INCLUDE =		include/so_long.h \
				include/get_next_line.h

SRCS =			src/check_errors.c \
				src/key_input_exit.c \
				src/key_input.c \
				src/load_map.c \
				src/map.c \
				src/player.c \
				src/so_long.c \
				src/get_next_line.c \
				src/get_next_line_utils.c

OBJS = 			$(SRCS:src/%.c=obj/%.o)

all:			$(NAME)

$(NAME):		$(OBJS) lib/printf/libftprintf.a
				$(CC) $(FLAGS) $^ $(LIBMLX_FLAGS) -o $(NAME)

lib/printf/libftprintf.a:
				make -C $(LIB_PATH)

obj/%.o:		src/%.c $(INCLUDE)
				mkdir -p obj
				$(CC) $(CFLAGS) -I include -c $< -o $@

clean:
				make clean -C $(LIB_PATH)
				rm -rf obj

fclean:			clean
				make fclean -C $(LIB_PATH)
				rm -f so_long

re: 			fclean all

.PHONY:			all clean fclean re
