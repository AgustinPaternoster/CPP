CFLAGS =  -Wall -Wextra -Werror -Wimplicit-fallthrough=0 -std=c++98 -g -fsanitize=address
CC = c++
FILES = main.cpp Harl.cpp
HEADERS = Harl.hpp
NAME = harlFilter
MODE = none


all : $(NAME)

ifeq ($(MODE),noflag)
	CFLAGS = -g -fsanitize=address
endif

$(NAME)	: $(FILES) $(HEADERS) Makefile
		$(CC) $(CFLAGS) $(FILES) -o $(NAME)

clean	:

fclean	: 
		rm $(NAME)

re		: fclean all
