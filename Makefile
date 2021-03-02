
NAME = cub3d

CC = gcc

LIBOBJS	= ${LIBSRC:.c=.o}

CFLAGS	= -Wall -Werror -Wextra

libft/%.o: libft/%.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#instruction
%.o: %.c
    $(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
    $(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

$(NAME): $(LIBOBJS)
		ar rc $(NAME) $(LIBOBJS)
		ranlib $(NAME)

clean:
		rm -f *.o
fclean: clean
		rm -f $(NAME)

re: fclean all
