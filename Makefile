SRC = bmp_screen.c draw.c init.c key_press.c parser_specif.c parser_specif2.c \
 	parser.c player.c reys.c sprites_utils.c sprites.c textures.c utils.c \
	write_texture.c wrongs.c $(DIR_GNL)/get_next_line_utils.c $(DIR_GNL)/get_next_line.c

NAME = cub3D

CC = gcc

OBJS	= ${SRC:.c=.o}

LIBDIR	= libft
LIBA	= $(LIBDIR)/libft.a
#libx_opengl
LIB_MLX 	= minilibx
MLXLIBA		= $(LIB_MLX)/libmlx.a
DIR_GNL 	= get_next_line

INCLUDES = -I$(LIBDIR) -I$(LIB_MLX) -I$(DIR_GNL)

CFLAGS	= -g -Wall -Werror -Wextra
MLXLAGS = -lmlx	-framework	OpenGL -framework AppKit

HFILES = ft_cub.h

%.o $(DIR_GNL)/%.o:	%.c $(DIR_GNL)/%.c
		$(CC) $(CFLAGS) $(HFILES) -c $< -o $@

all:		$(NAME)

$(NAME):	$(LIBA) $(MLXLIBA) $(OBJS)
			$(CC) $(OBJS) $(INCLUDES) $(LIBA) $(MLXLIBA) $(MLXLAGS) -o $(NAME)

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
