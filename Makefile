SRC = main_pipex.c utils.c utils_2.c split_path.c path.c command.c inisialiser.c get_next_line_utils.c free.c

		
SRCB = main_bonus.c get_next_line.c get_next_line_utils.c inisialiser.c \
		utils.c utils_2.c split_path.c path.c command.c heredoc_bonus.c free.c

CFLAGS = -Wall -Wextra -Werror 

OBJS = ${SRC:.c=.o}
OBJSB = ${SRCB:.c=.o}

NAME = pipex
NAME_B = pipex_bonus

all : ${NAME}

bonus : ${NAME_B}

${NAME} : ${OBJS}
	${CC} -o ${NAME} ${OBJS}

${NAME_B} : ${OBJSB}
	${CC} -o ${NAME} ${OBJSB}
clean :
	${RM} ${OBJS} ${OBJSB}
fclean : clean
	${RM} ${NAME} ${NAME_B}
re: fclean all
