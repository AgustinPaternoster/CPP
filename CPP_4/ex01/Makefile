CC = g++
HEADERS = Animal.hpp Dog.hpp Cat.hpp Brain.hpp
FILES = Animal.cpp Cat.cpp Dog.cpp main.cpp Brain.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
NAME = brain

all: $(NAME)

$(NAME): $(HEADERS) $(FILES) Makefile
		$(CC) $(FLAGS) $(FILES) -o $(NAME)

clean:

fclean:
	rm -r $(NAME)

re: fclean all
