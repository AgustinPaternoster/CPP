CC = g++
HEADERS = AMateria.hpp 
FILES = AMateria.cpp main.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
NAME = materia

all: $(NAME)

$(NAME): $(HEADERS) $(FILES) Makefile
		$(CC) $(FLAGS) $(FILES) -o $(NAME)

clean:

fclean:
	rm -r $(NAME)

re: fclean all
