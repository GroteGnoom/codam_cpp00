NAME = phonebook
SRC = main.cpp

ifdef DEBUG
	CC=clang++
	FLAGS = -Wall -Wextra -fsanitize=address -DDEBUG=1 -g -std=c++98 -DDEBUG=1
else
	CC=c++
	FLAGS = -Wall -Wextra -Werror
endif

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
.PHONY: all 
