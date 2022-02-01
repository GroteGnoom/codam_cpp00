NAME = account
SRC = Account.cpp tests.cpp

ifdef DEBUG
	CC=clang++
	FLAGS = -Wall -Wextra -fsanitize=address -DDEBUG=1 -g -std=c++98
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
