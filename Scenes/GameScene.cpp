#include "GameScene.h"

void GameScene:: drawScene() {
    snake.draw();
    map.draw();
    score.draw();
    apple.draw();
    pause_button.draw();
    if (isPaused) {
        resume_button.draw();
        main_menu_button.draw();
    }
}

bool GameScene:: logic() {
    if (!isPaused) {
        snake.logic(score);
        apple.logic(snake, score);
    }
    if (!isPaused && pause_button.isPressed()) isPaused = true;
    if (isPaused && resume_button.isPressed()) isPaused = false;
    if (isPaused && main_menu_button.isPressed()) return false;
    drawScene();
    return true;
}

void GameScene:: event_logic(sf::Keyboard::Key key) {
    snake.set_keyboard_key(key);
}

GameScene:: GameScene(sf::RenderWindow& win, int rad) 
    : window(win), snake(win), apple(window), score(window), map(window), pause_button(window),
      resume_button(window), main_menu_button(window) {
        map.init();
        pause_button.setUp(sf::Vector2f(10, 10), "Images/PauseButton.png");
        resume_button.setUp(sf::Vector2f(window.getSize().x / 2.f - 143.5f, 400), "Images/ResumeButton.png");
        main_menu_button.setUp(sf::Vector2f(window.getSize().x / 2.f - 192.5f, 490), "Images/MainMenuButton.png");
}

