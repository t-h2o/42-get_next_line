SRCS	=	main.c get_next_line.c get_next_line_utils.c

BS		=	12

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

NAME	=	program

RM		=	rm -f


.c.o:
	${CC} ${FLAGS} -c -D BUFFER_SIZE=${BS} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${CC} ${FLAGS} -o ${NAME} -D BUFFER_SIZE=${BS} ${OBJS}

gcc:
	gcc -Wall -Wextra -Werror -g -o ${NAME} -D BUFFER_SIZE=${BS} ${SRCS} -fsanitize=address
	clear
	./${NAME} 
#	valgrind --leak-check=full ./${NAME}
	
	# to remove at the end	
# 	-g compiler a moitier et donne la ligne
# 	-fsanitize=address

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
#	norminette -RCheckDefine ${HEADER}

leak:
	valgrind --leak-check=full ./${NAME}

.PHONY: all clean fclean re bonus so
