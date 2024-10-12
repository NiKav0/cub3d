NAME = getnextline.a
CFILES = get_next_line.c get_next_line_utils.c \

OFILES = $(CFILES:%.c=%.o)

CC = gcc
W = -c -Wall -Werror -Wextra -g
HEADER = get_next_line.h

all : $(NAME)

$(NAME) : $(OFILES) $(HEADER)
	@$(CC) $(W) $(CFILES)
	@ar -rc $(NAME) $(OFILES)

%.o : %.c $(HEADER)
	@$(CC) $(CFILES) -c $<

clean:
	@rm -f $(OFILES)

fclean : clean
	@rm -f $(NAME)

re : fclean all


# NAME = getnextline.a

# CFILES = get_next_line.c get_next_line_utils.c
# OFILES = $(CFILES:.c=.o)

# CC = gcc -Wall -Werror -Wextra
# HEADER = get_next_line.h

# all : $(NAME)

# $(NAME): $(OFILES)
#     @$(CC) $(CFILES)
#     @ar -rc $(NAME) $(OFILES)

# %.o : %.c $(HEADER)
#     @$(CC) $(W) -c $<

# clean :
#     @rm -rf $(OFILES)

# fclean : clean
#     @rm -rf $(NAME)

# re : fclean all