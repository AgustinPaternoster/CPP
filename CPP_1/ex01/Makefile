CFLAGS =  -Wall -Wextra -Werror -std=c++98 -g #-fsanitize=address
CC = c++
FILES = main.cpp Zombie.cpp zombieHorde.cpp
NAME = zombie
HEADERS = Zombie.hpp

all : $(NAME)


$(NAME)	: $(FILES) $(HEADERS) Makefile
		$(CC) $(CFLAGS) $(FILES) $(HEADERS) -g -o $(NAME)

clean	:

fclean	: 
		rm $(NAME)

re		: fclean all
