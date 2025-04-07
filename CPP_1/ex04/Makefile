CFLAGS =  -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
CC = c++
FILES = File.cpp main.cpp
HEADERS = File.hpp
NAME = replace


all : $(NAME)


$(NAME)	: $(FILES) $(HEADERS) Makefile
		$(CC) $(CFLAGS) $(FILES) -g -o $(NAME)

clean	:

fclean	: 
		rm $(NAME)

re		: fclean all
