CC = g++
HEADERS = 
FILES =  main.cpp 
FLAGS = -g -fsanitize=address
NAME = btc

all: $(NAME)

$(NAME): $(FILES) Makefile
		$(CC) $(FLAGS) $(FILES) -o $(NAME)

clean:

fclean:
	rm -r $(NAME)

re: fclean all
