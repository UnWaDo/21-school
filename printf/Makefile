SOURCES = ft_printf.c
SOURCES_BONUS = 
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
HEADERS = ft_printf.h
NAME = libftprintf.a
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
.PHONY: all clean fclean re bonus libft test

$(NAME): $(OBJECTS) libft
	ar -ruv $(NAME) $(OBJECTS)

all: $(NAME)

libft:
	make -C $(LIBFT_PATH)

test: $(NAME) main.o
	$(CC) $(CFLAGS) $(NAME) main.o

%.o: %.c $(HEADERS) libft
	$(CC) $(CFLAGS) -o $@ -c $*.c

bonus: $(OBJECTS_BONUS)
	ar -ruv $(NAME) $(OBJECTS_BONUS)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all