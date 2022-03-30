
NAME 		=	fractol
CC 			=	gcc
FLAGS 		=	-Wall -Werror -Wextra -g 
LDFLAGS		=	-L$(LIBMLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework Appkit -O3

LIBFT_DIR	=	./libft/
LIBMLX_DIR	=	./mlx/
SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/
HEADER_DIR	=	./incs/

SRCS		=	./srcs/utils.c\
				./srcs/colors.c\
				./srcs/mlx_utils.c\
				./srcs/mandelbrot.c\
				./srcs/julia.c\
				./srcs/burning_ship.c\
				./srcs/main.c

HEADERS		=	./incs/fractol.h
OBJS		= $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
LIBFT		= $(addprefix $(LIBFT_DIR), libft.a)
LIBMLX		= $(addprefix $(LIBMLX_DIR), libmlx.a)


RM = rm -f

all:	$(LIBFT) $(LIBMLX) $(NAME)
$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c $(HEADERS) $(LIBFT) $(LIBMLX) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -O3 -I$(HEADERS_DIR) -Imlx -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX):
	make -C $(LIBMLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

clean:
		$(RM) -r $(OBJS_DIR)
		make clean -C $(LIBFT_DIR) fclean

fclean: clean
		$(RM) $(NAME)
		make clean -C $(LIBFT_DIR) fclean

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

re:	fclean $(OBJS_DIR) all

.PHONY:	all clean fclean re