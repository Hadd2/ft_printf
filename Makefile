NAME = libftprintf.a
CC = gcc -Wall -Wextra -Werror 
AR = ar rcs
SRC_DIR = sources
INCLUDES = -Iincludes -Isources
SOURCES = 	${SRC_DIR}/ft_printf.c \
			${SRC_DIR}/token.c \
			${SRC_DIR}/parser.c \
			${SRC_DIR}/scanner.c \
			${SRC_DIR}/format_char.c \
			${SRC_DIR}/format_str.c \
			${SRC_DIR}/format_uint.c \
			${SRC_DIR}/format_int.c \
			${SRC_DIR}/format_addr.c \
			${SRC_DIR}/utils.c \
			${SRC_DIR}/numbers.c

OBJECTS = ${SOURCES:.c=.o}

LIBFT_DIR = ./includes
LIBFT = ${LIBFT_DIR}/libft.a

all : ${NAME}

${LIBFT} : 
	make bonus -C ${LIBFT_DIR}

${NAME} : ${OBJECTS} ${LIBFT}
	cp ${LIBFT} ${NAME}
	${AR} ${NAME} ${OBJECTS} ${LIBFT}

%.o : %.c 
	${CC} ${INCLUDES} -c $< -o $@

bonus : all

debug : ${NAME}
	gcc -fsanitize=address,leak -lasan  test.c -o test -g3 -I. -L. -lftprintf
	./test | cat -e

clean : 
	make clean -C ${LIBFT_DIR}
	rm -f ${OBJECTS}

fclean : clean
	make clean -C ${LIBFT_DIR}
	rm -f ${NAME}

re : fclean all
