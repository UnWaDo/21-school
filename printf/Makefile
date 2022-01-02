SOURCES = ft_printf.c ft_printf_conversions.c ft_printf_output.c \
	ft_printf_lengths.c ft_formatting.c
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
HEADERS = ft_printf.h ft_printf_utils.h
NAME = libftprintf.a
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
.PHONY: all clean fclean re bonus test

$(NAME): $(OBJECTS) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@ar -crv $(NAME) $(OBJECTS)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

test: $(NAME) main.o
	@$(CC) $(CFLAGS) main.o $(NAME)
	@valgrind -q --leak-check=full --track-origins=yes ./a.out
	@rm ./a.out

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(LIBFT_PATH)

bonus: $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all