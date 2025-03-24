CFLAGS =  -Wall -Wextra -Werror -std=c++98
CC = c++
FILES = main.cpp
NAME = phonebook
HEADERS = phonebook.hpp

all : $(NAME)


$(NAME)	: $(FILES) Makefile
		$(CC) $(CFLAGS) $(FILES) $(HEADERS) -o $(NAME)

clean	:

clean	: 
		rm $(NAME)

re		: flclean all
