#include "Game.h"

Game::Game() : window(sf::VideoMode(HEIGHT, WIDTH), "SNAKE"),
         main_scene(HEIGHT, WIDTH, window),
         game_scene(HEIGHT, WIDTH, window) {
    window.setVerticalSyncEnabled(true);
}

void Game:: event_logic() {
    sf::Event event;
    while (window.pollEvent(event))
        if (event.type == sf::Event::Closed)
            window.close();
}

void Game:: logic() {
    bool flag = false;
    while (window.isOpen()) {
        event_logic();
        if (flag) game_scene.logic();
        else {
            main_scene.drawScene();
            flag = main_scene.logic();
        }
        window.display();
        window.clear(sf::Color(40, 42, 54));
    }
}
