#CFLAGS =  -Wall -Wextra -Werror -std=c++98
CFLAGS =  -std=c++98
CC = c++
FILES = Account.cpp test.cpp
NAME = account
HEADERS = Account.hpp

all : $(NAME)


$(NAME)	: $(FILES) $(HEADERS) Makefile
		$(CC) $(CFLAGS) $(FILES) $(HEADERS) -g -o $(NAME)

clean	:

fclean	: 
		rm $(NAME)

re		: fclean all
