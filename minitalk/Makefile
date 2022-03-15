HEADER = minitalk.h
CLIENT = client.c
SERVER = server.c
CLIENT_BONUS = client_bonus.c
SERVER_BONUS = server_bonus.c
OBJ_CLIENT = $(patsubst %.c,%.o,$(CLIENT))
OBJ_SERVER = $(patsubst %.c,%.o,$(SERVER))


all: server client

server: $(OBJ_SERVER) $(HEADER)
		gcc -Wall -Wextra -Werror server.c -o server

client: $(OBJ_CLIENT) $(HEADER)
		gcc -Wall -Wextra -Werror client.c -o client

clean:
		rm -f $(OBJ_SERVER) $(OBJ_CLIENT) server client
		rm -f $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS) server_bonus client_bonus

fclean: clean

re: clean fclean all bonus