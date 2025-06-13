CC = g++
HEADERS = Bureaucrat.hpp AForm.hpp ShrubberuyCreationForm.hpp RobotomyRequestForm.hpp\
			PresidentialPardonForm.hpp Intern.hpp
FILES = Bureaucrat.cpp main.cpp AForm.cpp ShrubberuyCreationForm.cpp RobotomyRequestForm.cpp\
			PresidentialPardonForm.cpp Intern.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
NAME = intern

all: $(NAME)

$(NAME): $(HEADERS) $(FILES) Makefile
		$(CC) $(FLAGS) $(FILES) -o $(NAME)

clean:

fclean:
	rm -r $(NAME)

re: fclean all
