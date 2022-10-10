NAME = sed

SRC = $(wildcard source/*.cpp)

OBJ = $(SRC:.cpp=.o)

CPP = c++ 
STD = -std=c++98
CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(STD) $(CFLAGS) $(OBJ)  -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re