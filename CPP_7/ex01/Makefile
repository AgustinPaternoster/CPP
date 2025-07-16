CC = c++
HEADERS = iter.hpp 
FILES =  main.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
NAME = iter

all: $(NAME)

$(NAME): $(HEADERS) $(FILES) Makefile
		$(CC) $(FLAGS) $(FILES) -o $(NAME)

clean:

fclean:
	rm -r $(NAME)

re: fclean all
