SOURCES = ft_printf.c ft_printf_conversions.c ft_printf_output.c \
	ft_printf_lengths.c
SOURCES_BONUS = 
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
HEADERS = ft_printf.h
NAME = libftprintf.a
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
.PHONY: all clean fclean re bonus test

$(NAME): $(OBJECTS) $(LIBFT)
	@$(eval LIBFT_OBJS = $(shell ar t $(LIBFT) | tr '\n' ' '))
	@echo $(LIBFT_OBJS) $(OBJECTS) 
	@ar x $(LIBFT)
	@ar -crv $(NAME) $(OBJECTS) $(LIBFT_OBJS)
	@rm $(LIBFT_OBJS)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

test: $(NAME) main.o
	$(CC) $(CFLAGS) main.o $(NAME)
	./a.out


%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

Makefile:	;
%.c:		;
%.h:		;

bonus: $(OBJECTS_BONUS)
	ar -ruv $(NAME) $(OBJECTS_BONUS)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all