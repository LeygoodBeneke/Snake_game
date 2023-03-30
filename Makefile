EXECFILE=build/snake.out
CFLAGS=-Wall -Werror -Wextra

default:
	mkdir -p build
	g++ *.cpp Scenes/*.cpp -o $(EXECFILE) -lsfml-graphics -lsfml-window -lsfml-system
run:
	./$(EXECFILE)
