CFLAGS =  -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
CC = c++
FILES = main.cpp ClapTrap.cpp
HEADERS = ClapTrap.hpp
NAME = claptrap
MODE = none


all : $(NAME)

$(NAME)	: $(FILES) $(HEADERS) Makefile
		$(CC) $(CFLAGS) $(FILES) -o $(NAME)

clean	:

fclean	: 
		rm $(NAME)

re		: fclean all
