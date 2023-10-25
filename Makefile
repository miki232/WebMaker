NAME = web
CC = gcc
SRC = src/webmaker.c src/provca.c src/draw.c
OBJ = $(SRC:.c=.o)

ifeq ($(shell uname -s),Linux)
	CFLAGS = mlx/libmlx.a -g -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm
	MAKE_MLX = make -C ./mlx
else ifeq ($(shell uname -s),Darwin)
	CFLAGS = -g -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror
else
	$(error Unsupported operating system)
endif

%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(MAKE_MLX)
	$(CC) $(OBJ) libft/libft.a $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	make -C ./libft fclean
	make -C ./mlx clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
