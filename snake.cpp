#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <bits/stdc++.h>

enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    DEFAULT
};

#define RADIUS 10

class Snake {
public:
    void draw(sf:: RenderWindow &window) {
        window.draw(*head);
        head->move(vec_x, vec_y);
    }

    Snake() {
        vec_x = 0.01f;
        vec_y = 0.00f;
        dir = DEFAULT;
        head = new sf::CircleShape(RADIUS);
        head->setFillColor(sf::Color::Green);
        head->move(80, 100);
    };

    void logic(sf:: RenderWindow &window) {
        draw(window);
        dir = check_keyboard_key();
        if (is_int_coords()) {
            set_direction();
        }
    }

    ~Snake() {
        delete head;
    };

private:
    sf::CircleShape *head;
    Direction dir;
    float vec_x, vec_y;

    void set_direction() {
        if (dir == Direction::UP) {
            vec_y = -0.01f;
            vec_x = 0.00f;
        }
        if (dir == Direction::DOWN) {
            vec_y = 0.01f;
            vec_x = 0.00f;
        }
        if (dir == Direction::LEFT) {
            vec_y = 0.00f;
            vec_x = -0.01f;
        }
        if (dir == Direction::RIGHT) {
            vec_y = 0.00f;
            vec_x = 0.01f;
        }
    }

    bool is_int_coords() {
        float x = head->getPosition().x;
        float y = head->getPosition().y;
        return fabs(int(x) - x) <= 0.01f && int(x) % (RADIUS * 2) == 0 &&
               fabs(int(y) - y) <= 0.01f && int(y) % (RADIUS * 2) == 0;
    }

    enum Direction check_keyboard_key() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            return Direction::LEFT;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            return Direction::RIGHT;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            return Direction::UP;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            return Direction::DOWN;
        }
        return dir;
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    Snake s;

    sf::CircleShape apple(RADIUS);
    apple.setFillColor(sf::Color::Red);
    apple.setPosition(40, 60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        s.logic(window);
        window.draw(apple);
        window.display();
    }
    return 0;
}

