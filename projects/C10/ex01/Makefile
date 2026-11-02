CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_cat
SRCS = ft_cat.c \
	   ft_utility.c
OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ ${OBJS}

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
