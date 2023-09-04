NAME = push_swap

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f

SRCS =	operation.c push_swap.c utile_f.c ft_lst.c ft_split.c ft_msort.c ft_printf.c ft_strcmp.c

all :  ${NAME}

${NAME} :
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean :
	${RM} ${NAME}
fclean : clean
	${RM} ${NAME}
re : fclean all