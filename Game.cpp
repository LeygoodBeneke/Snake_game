#include "Game.h"

Game::Game() : window(sf::VideoMode(HEIGHT, WIDTH), "SNAKE"),
         main_scene(window),
         game_scene(window) {
    window.setVerticalSyncEnabled(true);
}

void Game:: event_logic() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
            game_scene.event_logic(event.key.code);
    }
}

void Game:: logic() {
    bool flag = false;
    while (window.isOpen()) {
        event_logic();
        if (flag) flag = game_scene.logic();
        else {
            main_scene.drawScene();
            flag = main_scene.logic();
        }
        window.display();
        window.clear(sf::Color(40, 42, 54));
    }
}
