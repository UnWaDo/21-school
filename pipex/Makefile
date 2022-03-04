SOURCES = pipex.c split_args.c pipex_utils.c \
			ft_split.c paths.c printf_min.c commands.c strings.c \
				forks.c
HEADERS = pipex.h
NAME = pipex
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
.PHONY: all clean fclean re norm

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SOURCES) $(HEADERS)