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

enum Direction check_keyboard_key(Direction dir) {
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

bool is_int_coords(float x, float y) {
    return fabs(int(x) - x) <= 0.01f && int(x) % (RADIUS * 2) == 0 &&
           fabs(int(y) - y) <= 0.01f && int(y) % (RADIUS * 2) == 0;
}

void set_direction(Direction dir, float &vec_x, float &vec_y) {
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

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::CircleShape shape(RADIUS);
    shape.setFillColor(sf::Color::Green);
    float vec_x = 0.01f, vec_y = 0.0f;
    Direction dir = DEFAULT;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        dir = check_keyboard_key(dir);



        shape.move(vec_x, vec_y);
        const sf:: Vector2f pos = shape.getPosition();
        
        if (is_int_coords(pos.x, pos.y)) {
            std:: cout << pos.x << ' ' << pos.y << ' ' << dir << '\n';
            set_direction(dir, vec_x, vec_y);
        }


        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

