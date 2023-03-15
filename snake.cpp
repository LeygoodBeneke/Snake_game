#include "SnakeClass.h"

void event_logic(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void game() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    Snake s;

    sf::CircleShape apple(RADIUS);
    apple.setFillColor(sf::Color::Red);
    apple.setPosition(40, 60);

    while (window.isOpen()) {
        event_logic(window);
        window.clear();
        s.logic(window);
        window.draw(apple);
        window.display();
    }
}

int main() {
    game();
    return 0;
}

