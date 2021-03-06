SRC = window.c parser.c get_next_line.c get_next_line_utils.c

NAME = cub3d

CC = gcc

OBJS	= ${SRC:.c=.o}

INCLUDES = 

LIBS = -L../ -L/Users/bcherie/cub3D/libmlx.a -lm

HEADER = 

CFLAGS	= -Wall -Werror -Wextra

libft/%.o: libft/%.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#instruction
%.o: %.c
    $(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
    $(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		rm -f *.o
fclean: clean
		rm -f $(NAME)

re: fclean all
