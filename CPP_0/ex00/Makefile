CFLAGS =  -Wall -Wextra -Werror -std=c++98
CC = c++
FILES = megaphone.cpp
NAME = megaphone

all : $(NAME)


$(NAME)	: $(FILES) Makefile
		$(CC) $(CFLAGS) $(FILES) -o $(NAME)

clean	:

clean	: 
		rm $(NAME)

re		: flclean all
