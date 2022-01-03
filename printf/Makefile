SOURCES = ft_printf.c args_int.c \
	args_other.c args_parsing.c args_utils_general.c \
	nums_bufferization.c
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
HEADERS = ft_printf.h ft_printf_utils.h
NAME = libftprintf.a
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
.PHONY: all clean fclean re bonus norm

$(NAME): $(OBJECTS) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@ar -crv $(NAME) $(OBJECTS)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

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

norm:
	norminette $(SOURCES) $(HEADERS)