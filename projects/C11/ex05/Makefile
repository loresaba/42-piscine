CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = do-op
SRCS = ft_conv_num.c \
	   ft_main.c \
	   ft_math_func.c \
	   ft_ops.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c ft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
