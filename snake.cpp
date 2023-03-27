#include "Scenes/MainScene.h"
#include "Scenes/GameScene.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

void event_logic(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void show_fps(sf:: Clock& clock) {
    float curr_time = clock.restart().asSeconds();
    float fps = 1.0f / curr_time;
    std:: cout << "fps: " << fps << '\n';
}

void game() {
    int h = 1920, w = 1080;
    sf::RenderWindow window(sf::VideoMode(h, w), "Snake");
    window.setVerticalSyncEnabled(true);
    GameScene game_scene(h, w, window);
    MainScene ms(h, w, window);

    sf::Clock clock;
    bool flag = false;

    while (window.isOpen()) {
        //show_fps(clock);
        event_logic(window);
        if (flag) {
            game_scene.logic();
        } else {
            ms.drawScene();
            flag = ms.logic();
        }
        window.display();
        window.clear(sf::Color(40, 42, 54));
    }
}

int main() {
    game();
    return 0;
}

