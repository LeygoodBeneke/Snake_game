#include "GameScene.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>


void GameScene:: drawScene() {
    snake.draw();
    score.draw(window);
    map.draw(window);
    apple.draw(window);
}

void GameScene:: logic() {
    if (!isPaused) {
        snake.logic(score);
        apple.logic(snake, score);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        isPaused = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        isPaused = false;
    drawScene();
}

void GameScene:: event_logic(sf::Keyboard::Key key) {
    snake.set_keyboard_key(key);
}

GameScene:: GameScene(int h, int w, sf::RenderWindow& win) 
    : height(h), width(w), window(win), snake(h, w, win), apple(h, w), score(h, w), map(h / (RADIUS * 2), w / (RADIUS * 2) - 2) {
        map.init();
    }

