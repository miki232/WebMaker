
NAME = web

CC = gcc

CFLAGS = -g -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm

SRC = src/main.c 

OBJ = $(SRC:.c=.o)

.%o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(OBJ)  mlx/libmlx.a libft/libft.a $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean