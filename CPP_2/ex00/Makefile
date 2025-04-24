CFLAGS =  -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
CC = c++
FILES = Fixed.cpp main.cpp 
HEADERS = Fixed.hpp
NAME = fixed
MODE = none


all : $(NAME)

$(NAME)	: $(FILES) $(HEADERS) Makefile
		$(CC) $(CFLAGS) $(FILES) -o $(NAME)

clean	:

fclean	: 
		rm $(NAME)

re		: fclean all
