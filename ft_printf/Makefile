NAME	= libftprintf.a

HEADER	= ft_printf.h

SRC		= ft_printf.c\
			ft_print_c.c\
			ft_print_str.c\
			ft_print_d.c\
			ft_print_p.c\
			ft_print_u.c\
			ft_print_x.c\

OBJ		= ${patsubst %.c,%.o,${SRC}}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:		${NAME}

${NAME}:	${OBJ} ${HEADER}
			ar rcs ${NAME} $?

%.o : %.c	${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re