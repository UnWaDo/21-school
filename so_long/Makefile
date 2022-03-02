SOURCES = map.c main.c hero.c system.c mlx_init.c so_long_exit.c mlx_utils.c
LIBFT_PATH = ./libft
PRINTF_PATH = ./printf
PRINTF = $(PRINTF_PATH)/libftprintf.a
HEADERS = so_long.h so_long_mlx.h so_long_utils.h
NAME = so_long
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LFLAGS = -lmlx -lX11 -lXext
.PHONY: all clean fclean re norm

$(NAME): $(OBJECTS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJECTS) $(PRINTF) $(LFLAGS) -o $(NAME)

all: $(NAME)

$(PRINTF):
	make -C $(PRINTF_PATH)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(LIBFT_PATH) -I$(PRINTF_PATH)

clean:
	make -C $(PRINTF_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(PRINTF_PATH) fclean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SOURCES) $(HEADERS)