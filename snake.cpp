#include "Apple.h"

void event_logic(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void game() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    Snake snake;
    Apple apple;
    Score score;


    sf::Clock clock;
    window.setFramerateLimit(60.0f);

    while (window.isOpen()) {

        float curr_time = clock.restart().asSeconds();
        float fps = 1.0f / curr_time;
        std:: cout << "fps: " << fps << '\n';
        event_logic(window);
        window.clear();
        snake.logic(window, score);
        apple.logic(snake, score);
        apple.draw(window);

 //       window.draw(apple);
        score.draw(window);
        window.display();
    }
}

int main() {
    game();
    return 0;
}

