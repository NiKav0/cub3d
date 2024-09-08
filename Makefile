CC = gcc
CFLAGS = -Wall -Wextra -Werror -ggdb
SRCS = main.c parse_textures.c parse_infos.c parse_rgb.c before_map.c \
	   utils.c utils2.c ./getnextline/get_next_line.c ./getnextline/get_next_line_utils.c 
LIBFT = ./libft/libft.a
OBJS = $(SRCS:.c=.o)
EXEC = cub3D
HEADER = ./getnextline/get_next_line.h

all: $(EXEC)

$(EXEC): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) $(LIBFT)
clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(EXEC)

re: fclean all
