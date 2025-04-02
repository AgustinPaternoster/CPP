CFLAGS =  -Wall -Wextra -Werror -std=c++98
CC = c++
FILES = main.cpp phonebook.cpp contact.cpp
NAME = phonebook
HEADERS = PhoneBook.hpp Contact.hpp

all : $(NAME)


$(NAME)	: $(FILES) $(HEADERS) Makefile
		$(CC) $(CFLAGS) $(FILES) -o $(NAME)

clean	:

fclean	: 
		rm $(NAME)

re		: fclean all
