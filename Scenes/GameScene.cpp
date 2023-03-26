#include "GameScene.h"


void GameScene:: drawScene() {
    score.draw(window);
    map.draw(window);
    apple.draw(window);
}

void GameScene:: logic() {
    snake.logic(window, score);
    apple.logic(snake, score);
    drawScene();
}

GameScene:: GameScene(int h, int w, sf::RenderWindow& win) 
    : height(h), width(w), window(win), snake(h, w), apple(h, w), score(h, w), map(h / 20, w / 20 - 2) {
        map.init();
    }

