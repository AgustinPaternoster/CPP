CC = g++
HEADERS = AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp
FILES = AMateria.cpp main.cpp Ice.cpp Cure.cpp Character.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
NAME = materia

all: $(NAME)

$(NAME): $(HEADERS) $(FILES) Makefile
		$(CC) $(FLAGS) $(FILES) -o $(NAME)

clean:

fclean:
	rm -r $(NAME)

re: fclean all
