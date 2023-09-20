NAME = minishell

SRCS = main.c \
utils.c \
utils_bis.c \
signal.c \
parsing.c \
dollar.c \
linked_list.c \
linked_list_bis.c \
free.c \
lex.c \
parse_redir.c \
pipe.c \
exec.c \
exit_code.c \
redir.c \
heredoc.c \
norme.c \
fix_echo.c \
split_custom.c \
Built_in/env.c \
Built_in/export.c \
Built_in/export_bis.c \
Built_in/add_var_export.c \
Built_in/unset.c \
Built_in/check_built_in.c \
Built_in/cd.c \
Built_in/pwd.c \
Built_in/echo.c \
Built_in/exit.c \

CC = gcc -Wall -Wextra -Werror -g3

MY_OBJECTS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

LIB = -lreadline -L/Users/$$USER/.brew/opt/readline/lib

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I /Users/$$USER/.brew/opt/readline/include -c $< -o $(<:.c=.o)

$(NAME): $(MY_OBJECTS)
	$(MAKE) -C libft bonus
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIB) $(LIBFT) -o $(NAME)

debug: $(MY_OBJECTS)
	$(MAKE) -C libft bonus
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIB) -fsanitize=address $(LIBFT) -o $(NAME)

RM=rm -f

clean:
	$(RM) $(MY_OBJECTS)
	$(MAKE) -C libft clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C libft fclean

re:	fclean all