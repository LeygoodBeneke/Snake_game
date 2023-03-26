#include "Map.h"
#include "Apple.h"
#include "Scenes/MainScene.h"

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
    int h = 1280, w = 720;
    sf::RenderWindow window(sf::VideoMode(h, w), "Snake");
    window.setVerticalSyncEnabled(true);
    Snake snake(h, w);
    Apple apple(h, w);
    Score score(h, w);
    Map map(h / 20, w / 20 - 2);

    MainScene ms(h, w, window);
    map.init();

    sf::Clock clock;
    bool flag = false;

    while (window.isOpen()) {
        show_fps(clock);
        event_logic(window);
        if (flag) {
            snake.logic(window, score);
            apple.logic(snake, score);

            score.draw(window);
            map.draw(window);
            apple.draw(window);
        } else {
            ms.drawScene(window);
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

