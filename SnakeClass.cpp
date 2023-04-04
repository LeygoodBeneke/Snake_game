#include "SnakeClass.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

void Snake:: draw() {
    for (size_t i = 0; i < head.size(); i++) window.draw(head[i]);
}

void Snake:: add_body() {
    head.push_back(sf::CircleShape(radius));
    head.back().setFillColor(sf::Color::Green);
    cur_coords.push_back(sf::Vector2f(0.0f, 0.0f));
    if (head.size() < 2) head.back().setPosition(radius * 8, radius * 10);
    else head.back().setPosition(head[head.size() - 2].getPosition().x, head[head.size() - 2].getPosition().y);
}

Snake:: Snake(sf::RenderWindow& win, int rad, float spd)
    : window(win), radius(rad), speed(spd) {
    vec_x = speed;
    vec_y = 0.00f;
    dir = sf::Keyboard::Right;
    add_body();
}

float Snake:: get_motion_value(int left, int right) {
    if (left > right) return speed;
    if (left == right) return 0.0;
    return -speed;
}

sf::Vector2f Snake:: get_motion_vector(size_t idx) {
    float move_x = get_motion_value(cur_coords[idx - 1].x, head[idx].getPosition().x);
    float move_y = get_motion_value(cur_coords[idx - 1].y, head[idx].getPosition().y);
    return sf::Vector2f(move_x, move_y);
}

void Snake:: check_head_position() {
    if (head[0].getPosition().y < radius * 4 && vec_y < 0) head[0].setPosition(head[0].getPosition().x, window.getSize().y - radius * 4);
    if (head[0].getPosition().y > window.getSize().y - radius * 2 && vec_y > 0) head[0].setPosition(head[0].getPosition().x, radius * 4);
    if (head[0].getPosition().x < 0 && vec_x < 0) head[0].setPosition(window.getSize().x - radius, head[0].getPosition().y);
    if (head[0].getPosition().x > window.getSize().x - radius * 2 && vec_x > 0) head[0].setPosition(0, head[0].getPosition().y);
}

void Snake:: body_movement(int idx) {
    head[idx].move(get_motion_vector(idx));
    if (std:: fabs(cur_coords[idx - 1].y - head[idx].getPosition().y) > radius * 2)
        head[idx].setPosition(head[idx].getPosition().x, cur_coords[idx - 1].y);
    if (std:: fabs(cur_coords[idx - 1].x - head[idx].getPosition().x) > radius * 2)
        head[idx].setPosition(cur_coords[idx - 1].x, head[idx].getPosition().y);
}

void Snake:: movement() {
    head[0].move(vec_x, vec_y);
    check_head_position();
    for (size_t i = 1; i < head.size(); i++) body_movement(i);
}

void Snake:: update_cur_coords() {
    for (size_t i = 0; i < head.size(); i++)
        cur_coords[i] = head[i].getPosition();
}

void Snake:: collision(Score &score) {
    for (size_t i = 1; i < head.size(); i++) {
        if (head[0].getPosition() == head[i].getPosition()) {
            head.resize(i + 1);
            cur_coords.resize(i + 1);
            score.set_score(i + 1);
            break;
        }
    }
}

void Snake:: logic(Score &score) {
    if (is_int_coords()) {
        set_direction();
        update_cur_coords();
        collision(score);
    }
    movement();
}

Snake:: ~Snake() {}


void Snake:: set_direction() {
    vec_x = speed * (dir == sf::Keyboard::Left ? -1 : 1);
    vec_y = speed * (dir == sf::Keyboard::Up ? -1 : 1);
    if (dir == sf::Keyboard::Up || dir == sf::Keyboard::Down) vec_x = 0.00f;
    if (dir == sf::Keyboard::Left || dir == sf::Keyboard::Right) vec_y = 0.00f;
}

bool Snake:: is_int_coords() {
    float x = head[0].getPosition().x, y = head[0].getPosition().y;
    return fabs(int(x) - x) <= 0.01f && int(x) % (radius * 2) == 0 &&
           fabs(int(y) - y) <= 0.01f && int(y) % (radius * 2) == 0;
}

void Snake:: set_keyboard_key(sf::Keyboard::Key key) { dir = key; }

sf:: Vector2f Snake:: get_head_pos() {
    return head.front().getPosition();
}
