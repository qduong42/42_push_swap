CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line
SRCS =  get_next_line.c get_next_line_utils.c get_next_line.h get_next_line_bonus.c get_next_line_bonus.h get_next_line_utils_bonus.c
OBJS = ${SRCS:.c=.o} #makes *.o from *.c
BONUS_OBJS = ${BONUS_SRCS:.c=.o} 
RM = rm -f
CC = gcc

# -D BUFFER_SIZE=3

all: 
	gcc $(CFLAGS) -o $(NAME) -g  -D BUFFER_SIZE=1000 $(SRCS)
	./$(NAME)

clean:
	${RM} ${OBJS} $(BONUS_OBJS)

fclean: clean
	${RM} $(NAME) 

re: fclean all

.PHONY:	all clean fclean re 

no: $(SRCS)
	norminette $(SRCS)
git: $(SRCS)
	git add $(SRCS)