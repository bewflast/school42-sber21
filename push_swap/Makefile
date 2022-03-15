NAME = push_swap

SRC = ft_atoi.c\
		ft_list.c\
		ft_ops.c\
		ft_stack.c\
		ft_push_swap.c\
		ft_sorts.c\
		ft_sorts_utils.c

OBJ = $(SRC:.c=.o)

HDRS = ft_atoi.h\
		ft_list.h\
		ft_ops.h\
		ft_stack.h\
		ft_sorts.h\
		ft_sorts_utils.h

BNAME = checker

BSRC = ft_atoi.c\
		ft_list.c\
		ft_ops.c\
		ft_stack.c\
		ft_sorts.c\
		ft_sorts_utils.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_checker.c

BOBJ = $(BSRC:.c=.o)

BHDRS = $(HDRS) get_next_line.h

CC = gcc

FLAGS = -g -Wall -Wextra -Werror

RM = rm -f

$(NAME): $(HDRS) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(BNAME): $(BHDRS) $(BOBJ)
		$(CC) $(FLAGS) $(BOBJ) -o $(BNAME)

all: $(NAME)

bonus: $(BNAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(BOBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(BNAME)

re:	fclean all

.PHONY: all clean fclean bonus