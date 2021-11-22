SRCS	= main.c get_next_line.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

NAME	= program

RM		= rm -f


.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean	all

log:
	git log --graph --oneline

norm:
	norminette ${SRCS}
	norminette -RCheckDefine ${HEADER}

.PHONY: all clean fclean re bonus so
