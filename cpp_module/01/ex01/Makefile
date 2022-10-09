NAME = zombastiki

SRC = source/zombieHorde.cpp		\
		source/main.cpp				\
		source/Zombie.cpp

OBJ = $(SRC:.cpp=.o)

CPP = c++ 
STD = -std=c++98
CPPFLAGS = -Wall -Wextra -Werror -I./include/

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(STD) $(CFLAGS) $(OBJ)  -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re