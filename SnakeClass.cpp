#include "SnakeClass.h"

void Snake:: draw(sf:: RenderWindow &window) {
        window.draw(*head);
        head->move(vec_x, vec_y);
    }

Snake:: Snake() {
    vec_x = 0.01f;
    vec_y = 0.00f;
    dir = DEFAULT;
    head = new sf::CircleShape(RADIUS);
    head->setFillColor(sf::Color::Green);
    head->move(80, 100);
}

void Snake:: logic(sf:: RenderWindow &window) {
    draw(window);
    dir = check_keyboard_key();
    if (is_int_coords()) {
        set_direction();
    }
}

Snake:: ~Snake() {
    delete head;
}


void Snake:: set_direction() {
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

bool Snake:: is_int_coords() {
    float x = head->getPosition().x, y = head->getPosition().y;
    return fabs(int(x) - x) <= 0.01f && int(x) % (RADIUS * 2) == 0 &&
           fabs(int(y) - y) <= 0.01f && int(y) % (RADIUS * 2) == 0;
}

enum Direction Snake:: check_keyboard_key() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return Direction::LEFT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return Direction::RIGHT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        return Direction::UP;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        return Direction::DOWN;
    return dir;
}
