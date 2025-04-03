CFLAGS =  -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
CC = c++
FILES = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
HEADERS = HumanA.hpp HumanA.hpp Weapon.cpp
NAME = uviolence


all : $(NAME)


$(NAME)	: $(FILES) $(HEADERS) Makefile
		$(CC) $(CFLAGS) $(FILES) $(HEADERS) -g -o $(NAME)

clean	:

fclean	: 
		rm $(NAME)

re		: fclean all
