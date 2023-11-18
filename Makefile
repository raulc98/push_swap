NAME = push_swap
CHECK = checker

SRCS =  $(wildcard src/*.c src/sorter/*.c src/instructions/*.c src/utils/*.c src/libft_utils/*.c)
CHECK_SRCS = $(wildcard src/*.c src/sorter/*.c src/instructions/*.c src/utils/*.c src/libft_utils/*.c)

OBJS = ${SRCS:.c=.o}
CHECK_OBJS = ${CHECK_SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME} ${CHECK}
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${CHECK}: ${CHECK_OBJS} 
	@${CC} ${CFLAGS} ${CHECK_OBJS} -o ${CHECK}

clean: 
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all

.PHONY: all clean fclean re
