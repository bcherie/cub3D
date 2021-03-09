SRC = window.c parser.c screen.c $(DIR_GNL)/get_next_line_utils.c $(DIR_GNL)/get_next_line.c

NAME = cub3d

CC = gcc

OBJS	= ${SRC:.c=.o}

LIBDIR	= libft
LIBA	= $(LIBDIR)/libft.a
LIB_MLX 	= libx_opengl
MLXLIBA		= $(LIB_MLX)/libmlx.a
DIR_GNL 	= get_next_line
#SRC_GNL 	= $(DIR_GNL)/get_next_line.c $(DIR_GNL)/get_next_line_utils.c
#OBJ_GNL		= $(DIR_GNL)/get_next_line.o $(DIR_GNL)/get_next_line_utils.o

INCLUDES = -I$(LIBDIR) -I$(LIB_MLX) -I$(DIR_GNL)

CFLAGS	= -g -Wall -Werror -Wextra
MLXLAGS = -lmlx	-framework	OpenGL -framework AppKit

HFILES = ft_cub.h

#cub3D/%.o: cub3D/%.c
#		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#instruction

#%.o:	%.c $(HFILES)
#		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

$(NAME):	$(LIBA) $(MLXLIBA) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBA) $(MLXLIBA) $(MLXLAGS) -o $(NAME)


#gnl:
#			$(CC) -c $(CFLAGS) $(SRC_GNL)
	
$(LIBA):		
			$(MAKE) -j4 -C $(LIBDIR)
$(MLXLIBA):		
			$(MAKE) -j4 -C $(LIB_MLX)

clean:
		rm -rf $(OBJS) *.a *.dSYM *.dylib
		$(MAKE) clean -C $(LIBDIR)
		$(MAKE) clean -C $(LIB_MLX)

fclean: clean
			rm -f $(NAME)
			$(MAKE) fclean -C $(LIBDIR)

re:			fclean all
