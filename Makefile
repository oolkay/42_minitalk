SERVER_NAME = server
CLIENT_NAME = client
CC = gcc
FLAGS = -Wall -Werror -Wextra

all: ${SERVER_NAME} $(CLIENT_NAME) norminette

${SERVER_NAME}: src/server.o src/utils.o
	@$(CC) $(FLAGS) src/server.o src/utils.o -o $(SERVER_NAME)
	@printf $(yellow)
	@printf "Compiling server...\n"
	@sleep 0.5
	

${CLIENT_NAME}: src/client.o src/utils.o
	@$(CC) $(FLAGS) src/client.o src/utils.o -o $(CLIENT_NAME)
	@printf $(yellow)
	@printf "Compiling client...\n"
	@sleep 0.5
	@printf $(green)
	@printf "Executables are ready...\n"
	@sleep 0.5

bonus: bonus/client_bonus.o bonus/server_bonus.o src/utils.o
	@$(CC) $(FLAGS) bonus/server_bonus.o src/utils.o -o $(SERVER_NAME)
	@$(CC) $(FLAGS) bonus/client_bonus.o src/utils.o -o $(CLIENT_NAME)
	@printf $(cyan)
	@printf "Compiling bonuses...\n"
	@printf "Executable bonuses are ready...\n"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)	

clean:
	@rm -f src/*.o
	@rm -f bonus/*.o

fclean: clean
	@printf $(red)
	@printf "Cleaning...\n"
	@rm -f ${SERVER_NAME} ${CLIENT_NAME}
	@sleep 0.5
	@printf "The files has been cleaned...\n"

norminette:
	@printf ${magenta}
	@norminette

re: fclean all

.PHONY: all clean re fclean norminette

####	C	O	L	O	R	S	####
black 				=	"[1;30m"
red 				=	"[1;31m"
green 				=	"[1;32m"
yellow 				=	"[1;33m"
blue 				=	"[1;34m"
magenta 			=	"[1;35m"
cyan 				=	"[1;36m"
white 				=	"[1;37m"
####	C	O	L	O	R	S	####