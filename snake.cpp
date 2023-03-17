#include "SnakeClass.h"
#include "Apple.h"

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
    Apple a;

//    sf::CircleShape apple(RADIUS);
//    apple.setFillColor(sf::Color::Red);
//    apple.setPosition(40, 60);

    sf::Clock clock;
    window.setFramerateLimit(60);

    while (window.isOpen()) {

        float curr_time = clock.restart().asSeconds();
        float fps = 1.0f / curr_time;
        std:: cout << "fps: " << fps << '\n';
        event_logic(window);
        window.clear();
        s.logic(window);
        a.logic(s.get_head_pos());
        a.draw(window);

 //       window.draw(apple);
        window.display();
    }
}

int main() {
    game();
    return 0;
}

