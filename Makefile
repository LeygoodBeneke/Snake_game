EXECFILE=snake.out
CFLAGS=-Wall -Werror -Wextra

build:
	g++ *.cpp Scenes/*.cpp -o $(EXECFILE) -lsfml-graphics -lsfml-window -lsfml-system
run:
	./$(EXECFILE)
