SRC = main.cpp parser.cpp vm.cpp instruction.cpp lexer.cpp factory.cpp operand.cpp
OUT = vm
FLAGS = -Wall -Werror -Wextra -std=c++11
COMP = g++

all:
	$(COMP) $(SRC) -o $(OUT) $(FLAGS)

clean:
	rm -rf $(OUT) custom.avm

fclean: clean

re: fclean
	make all