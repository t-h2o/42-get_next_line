NAME	=	program	


#	Compilation setting

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
BS		=	42


#	Directories

DIR_SRC	=	./srcs
DIR_OBJ	=	./objs
DIR_INC	=	./headers/


#	Sources

SRCS	=	${DIR_SRC}/main.c			\
			${DIR_SRC}/get_next_line.c	\
			${DIR_SRC}/get_next_line_utils.c


OBJS	=	${addprefix ${DIR_OBJ}/, ${notdir ${SRCS:.c=.o}}}

HEADER	=	${DIR_INC}get_next_line.h

RM		=	rm -f


vpath %.c ${DIR_SRC}


all : ${NAME}


${NAME}:	${OBJS}
	${CC} ${FLAGS} -o ${NAME}  ${OBJS}

${DIR_OBJ}/%.o : %.c | ${DIR_OBJ}
	${CC} ${CFLAGS} -D BUFFER_SIZE=${BS} -I ${DIR_INC} -o $@ -c $^

${DIR_OBJ} :
	@mkdir -p ${DIR_OBJ}


clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all


norm:
	norminette ${SRCS}
	norminette ${HEADER}
