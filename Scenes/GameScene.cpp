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

GameScene:: GameScene(sf::RenderWindow& win, int rad) 
    : window(win),
      snake(win),
      apple(window),
      score(window),
      map(window.getSize().x / (rad * 2), window.getSize().y / (rad * 2) - 2) {
        map.init();
    }

