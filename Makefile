NAME = libftprintf.a
CC = gcc
FLAGS = -c -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c\
	ft_parser.c\
	ft_type_char.c\
	ft_type_int.c\
	ft_type_uint.c\
	ft_utils.c\
	ft_type_str.c\
	ft_type_hex.c\
	ft_itoa_base.c\
	ft_type_pointer.c\

OBJS = ft_printf.o\
	ft_parser.o\
	ft_type_char.o\
	ft_type_int.o\
	ft_type_uint.o\
	ft_utils.o\
	ft_type_str.o\
	ft_type_hex.o\
	ft_itoa_base.o\
	ft_type_pointer.o\

.c.o:
	${CC} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CC} ${FLAGS} ${SRC}
			ar -rcs ${NAME} ${OBJS}

all: 		${NAME}

clean:
			rm -rf ${OBJS}

fclean:	clean
			rm -rf libftprintf.a

re: 		fclean all

.PHONY: all clean fclean
