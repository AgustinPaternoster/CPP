CFLAGS =  -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
CC = c++
FILES = main.cpp
NAME = thisbrain


all : $(NAME)


$(NAME)	: $(FILES) $(HEADERS) Makefile
		$(CC) $(CFLAGS) $(FILES) $(HEADERS) -g -o $(NAME)

clean	:

fclean	: 
		rm $(NAME)

re		: fclean all
