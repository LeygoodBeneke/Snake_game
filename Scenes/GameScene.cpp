#include "GameScene.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

void GameScene:: drawScene() {
    snake.draw();
    map.draw();
    score.draw();
    apple.draw();
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

GameScene:: GameScene(sf::RenderWindow& win, int rad) 
    : window(win), snake(win), apple(window), score(window), map(window) {
        map.init();
}

