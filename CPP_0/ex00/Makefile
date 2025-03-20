CFLAGS =  -Wall -Wextra -Werror
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
