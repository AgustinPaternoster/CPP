CC = g++
HEADERS = Array.hpp Array.tpp
FILES =  main.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
NAME = array

all: $(NAME)

$(NAME): $(HEADERS) $(FILES) Makefile
		$(CC) $(FLAGS) $(FILES) -o $(NAME)

clean:

fclean:
	rm -r $(NAME)

re: fclean all
