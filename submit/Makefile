CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = main.c check.c list_utils.c operations.c operations_2.c sort5_and_less.c push.c radix.c
OBJS = ${SRCS:.c=.o} #makes *.o from *.c
RM = rm -f
CC = gcc

all: $(NAME)

$(NAME): ${OBJS}
	$(MAKE) -C libft
	$(CC) $(OBJS) libft/libft.a -o $(NAME)

clean:
	${RM} ${OBJS} $(BONUS_OBJS)
	$(RM) libft/*.o

fclean: clean
	${RM} $(NAME)
	$(RM) libft/libft.a

re: fclean all

.PHONY:    all clean fclean re

git add:	$(SRCS)
	rm -rf *.o libft/*.o
	git add $(SRCS) push_swap.h libft

norm:	$(SRCS)
	norminette $(SRCS) libft/ push_swap.h