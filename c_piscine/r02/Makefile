CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SANIT	=	-fsanitize=address -static-libsan
NAME	=	rush-02
EXEC	=	$(NAME)
SRCS_F	=	main.c ft_io.c ft_strings.c ft_strings_compare.c ft_parser.c \
			ft_strings_mem.c ft_list.c ft_trim_spaces.c ft_memory.c ft_dict.c ft_dict_sorter.c
S_DIR	=	srcs/
I_DIR	=	includes/
SRCS	=	$(addprefix $(S_DIR),$(SRCS_F))
OBJS	=	$(SRCS:.c=.o)
DOBJS	=	$(OBJS:.o=D.o)
DEXEC	=	$(addprefix D_,$(EXEC))
INCL	=	$(addprefix -I ,$(I_DIR))
RELEASE	=	$(CC) $(CFLAGS) $(INCL)
DEBUG	=	$(RELEASE) $(SANIT) -g
.PHONY:	all clean fclean norm

all:		$(EXEC)

$(EXEC):	$(OBJS)
	$(RELEASE) -o $(EXEC) $(OBJS)

%.o:		%.c
	$(RELEASE) -o $@ -c $<

%D.o:		%.c
	$(DEBUG) -o $@ -c $<

debug:		$(DEXEC)

$(DEXEC):	$(DOBJS)
	$(DEBUG) -o $(DEXEC) $(DOBJS)

clean:
	rm -rf $(OBJS)

dclean:
	rm -rf $(DOBJS)

dfclean:	dclean
	rm -rf $(DEXEC)

fclean:		clean	dfclean
	rm -rf $(EXEC)

re:			fclean $(EXEC)

norm:
	norminette -R CheckForbiddenSourceHeader $(S_DIR)*.c
	norminette -R CheckDefine $(I_DIR)*.h
