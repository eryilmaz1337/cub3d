NAME		= libft.a
LIBFT		= ./lib/libft/
MLX			= ./lib/mlx/
CC			= gcc
FLAGS		= -framework OpenGL -framework AppKit -L ./lib/mlx -Wall -Wextra -Werror
FILE		= ./src/move/*.c \
				./src/graphic/*.c \
				./src/map_src/*.c \
				./src/exit/*.c \
				./src/main/*.c \
				./lib/get_next_line/get_next_line.c \
				./lib/get_next_line/get_next_line_utils.c \
				./src/archive/libft.a \
				./src/archive/libmlx.a \
#./src/leacks_cheker_ex.c
RM			= rm -f
AR			= ar rcs

SRC			= $(wildcard src/*.c)

all:		$(NAME) compilation

$(NAME):
			make -C $(LIBFT)
			make -C $(MLX)
			cp lib/libft/libft.a src/archive/
			cp lib/mlx/libmlx.a src/archive/

compilation:
			$(CC) $(FLAGS) $(FILE)
			mv ./a.out cub3d

clean:
			rm -f ./src/archive/libft.a
			rm -f ./src/archive/libmlx.a
			make clean -C $(LIBFT)
			make clean -C $(MLX)

fclean:		clean
	@$(RM) -f ./src/libft.a
	@$(RM) -f $(LIBFT)/libft.a
	@$(RM) -f cub3d

re:			fclean all

.PHONY:		all clean fclean re derle
# all:
# 	gcc ./src/*.c ./lib/MLX42/libmlx42.a -lglfw -L /goinfre/homebrew/Cellar/glfw/3.3.8/lib/
