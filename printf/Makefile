NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra
SRCS=
OBJS=${SRCS:.c=.o}

all: $(NAME)

$(NAME) : ${OBJS}
	ar rcs $(NAME) ${OBJS}

clean:
	${RM} ${OBJS} $(BONUS_OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY:	all clean fclean re