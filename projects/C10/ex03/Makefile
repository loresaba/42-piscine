CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_hexdump
SRCS = ft_error.c \
	   ft_main.c \
	   ft_memory.c \
	   ft_parse_args.c \
	   ft_print_memory.c \
	   ft_print_memory_base.c \
	   ft_read_file.c \
	   ft_string.c \
	   ft_hexdump.c
HEADS = ft.h
OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ ${OBJS}

%.o:%.c $(HEADS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
