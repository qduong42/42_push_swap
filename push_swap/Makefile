CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = 
OBJS = ${SRCS:.c=.o} #makes *.o from *.c
RM = rm -f
CC = gcc

all: $(NAME)

clean:
    ${RM} ${OBJS} $(BONUS_OBJS)

fclean: clean
    ${RM} $(NAME)

re: fclean all

.PHONY:    all clean fclean re