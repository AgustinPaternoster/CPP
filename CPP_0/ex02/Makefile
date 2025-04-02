CFLAGS =  -Wall -Wextra -Werror -std=c++98
CC = g++
FILES = Account.cpp tests.cpp
NAME = account
HEADERS = Account.hpp

all : $(NAME)


$(NAME)	: $(FILES) $(HEADERS) Makefile
		$(CC) $(CFLAGS) $(FILES) -o $(NAME)

clean	:

fclean	: 
		rm $(NAME)

re		: fclean all
