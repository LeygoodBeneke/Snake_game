build:
	g++ -Wall -Werror -Wextra *.cpp Scenes/*.cpp -o snake.exe -lsfml-graphics -lsfml-window -lsfml-system
run:
	./snake.out
