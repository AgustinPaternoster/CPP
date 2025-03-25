CFLAGS =  -Wall -Wextra -Werror -std=c++98
CC = c++
FILES = main.cpp phonebook.cpp
NAME = phonebook
HEADERS = PhoneBook.hpp Contact.hpp

all : $(NAME)


$(NAME)	: $(FILES) $(HEADERS) Makefile
		$(CC) $(CFLAGS) $(FILES) $(HEADERS) -g -o $(NAME)

clean	:

clean	: 
		rm $(NAME)

re		: flclean all
