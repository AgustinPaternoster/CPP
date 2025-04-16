CFLAGS =  -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
CC = c++
FILES = Fixed.cpp main.cpp Point.cpp bsp.cpp
HEADERS = Fixed.hpp Point.hpp
NAME = bsp
MODE = none


all : $(NAME)

$(NAME)	: $(FILES) $(HEADERS) Makefile
		$(CC) $(CFLAGS) $(FILES) -o $(NAME)

clean	:

fclean	: 
		rm $(NAME)

re		: fclean all
