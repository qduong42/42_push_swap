CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = main.c check.c list_utils.c
OBJS = ${SRCS:.c=.o} #makes *.o from *.c
RM = rm -f
CC = gcc

all: $(NAME)

$(NAME): ${OBJS}
	$(CC) -g $(OBJS) libft/libft.a -o $(NAME)

clean:
	${RM} ${OBJS} $(BONUS_OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY:    all clean fclean re