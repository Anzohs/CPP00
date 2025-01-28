NAME = account
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS)

clean:
	@rm -rf $(OBJ)
	@echo "Objects clean"

fclean: clean
	@rm -rf $(NAME)
	@echo "Executable removed"

re: fclean all
