CFLAGS =  -Wall -Wextra -Werror -std=c++98 -fsanitize=address
CC = c++
FILES = main.cpp newZombie.cpp Zombie.cpp randomChump.cpp
NAME = zombie
HEADERS = Zombie.hpp

all : $(NAME)


$(NAME)	: $(FILES) $(HEADERS) Makefile
		$(CC) $(CFLAGS) $(FILES) $(HEADERS) -g -o $(NAME)

clean	:

fclean	: 
		rm $(NAME)

re		: fclean all
