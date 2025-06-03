CC = g++
HEADERS = 
FILES = 
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
NAME = bureu

all: $(NAME)

$(NAME): $(HEADERS) $(FILES) Makefile
		$(CC) $(FLAGS) $(FILES) -o $(NAME)

clean:

fclean:
	rm -r $(NAME)

re: fclean all
