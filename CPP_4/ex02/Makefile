CC = g++
HEADERS = AAnimal.hpp Dog.hpp Cat.hpp Brain.hpp
FILES = AAnimal.cpp Cat.cpp Dog.cpp main.cpp Brain.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
NAME = abstract

all: $(NAME)

$(NAME): $(HEADERS) $(FILES) Makefile
		$(CC) $(FLAGS) $(FILES) -o $(NAME)

clean:

fclean:
	rm -r $(NAME)

re: fclean all
