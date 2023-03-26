build:
	g++ -Wall -Werror -Wextra snake.cpp SnakeClass.cpp Apple.cpp Map.cpp Scenes/MainScene.cpp -o snake.out -lsfml-graphics -lsfml-window -lsfml-system
run:
	./snake.out
