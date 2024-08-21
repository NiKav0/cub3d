CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c map_parsing.c ./getnextline/get_next_line.c ./getnextline/get_next_line_utils.c
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
