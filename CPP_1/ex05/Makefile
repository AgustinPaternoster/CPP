CFLAGS =  -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
CC = c++
FILES = main.cpp Harl.cpp
HEADERS = Harl.hpp
NAME = harl
MODE = none


all : $(NAME)

ifeq ($(MODE),noflag)
	CFLAGS = -g -fsanitize=address
endif

$(NAME)	: $(FILES) $(HEADERS) Makefile
		$(CC) $(CFLAGS) $(FILES) -g -o $(NAME)

clean	:

fclean	: 
		rm $(NAME)

re		: fclean all
