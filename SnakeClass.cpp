#include "SnakeClass.h"
#include <SFML/Graphics/RenderWindow.hpp>

#define INIT_SIZE 1
#define RADIUS 10
#define SPEED 2.0f

void Snake:: draw() {
    for (size_t i = 0; i < head.size(); i++) window.draw(head[i]);
}

void Snake:: add_body() {
    head.push_back(sf::CircleShape(RADIUS));
    head.back().setFillColor(sf::Color::Green);
    cur_coords.push_back(sf::Vector2f(0.0f, 0.0f));
    if (head.size() < 2) head.back().setPosition(80.0f, 100.0f);
    else head.back().setPosition(head[head.size() - 2].getPosition().x, head[head.size() - 2].getPosition().y);
}

void Snake:: init_head() {
    for (int i = 0; i < INIT_SIZE; i++)
        add_body();
}

Snake:: Snake(int h, int w, sf::RenderWindow& win) : height(h), width(w), window(win) {
    vec_x = SPEED;
    vec_y = 0.00f;
    dir = DEFAULT;
    init_head();
}

float Snake:: get_motion(int left, int right) {
    if (left > right) return SPEED;
    if (left == right) return 0.0;
    return -SPEED;
}

void Snake:: movement() {
    head[0].move(vec_x, vec_y);
    if (head[0].getPosition().y < 40 && vec_y < 0) head[0].setPosition(head[0].getPosition().x, width - RADIUS * 2 - 20);
    if (head[0].getPosition().y > width - 20 && vec_y > 0) head[0].setPosition(head[0].getPosition().x, 40);
    if (head[0].getPosition().x < 0 && vec_x < 0) head[0].setPosition(height - RADIUS, head[0].getPosition().y);
    if (head[0].getPosition().x > height - 20 && vec_x > 0) head[0].setPosition(0, head[0].getPosition().y);
    for (size_t i = 1; i < head.size(); i++) {
        int move_x = get_motion(cur_coords[i - 1].x, head[i].getPosition().x);
        int move_y = get_motion(cur_coords[i - 1].y, head[i].getPosition().y);
        head[i].move(move_x, move_y);
        if (std:: fabs(cur_coords[i - 1].y - head[i].getPosition().y) > 20 &&
            head[i].getPosition().y) head[i].setPosition(head[i].getPosition().x, cur_coords[i - 1].y);
        if (std:: fabs(cur_coords[i - 1].x - head[i].getPosition().x) > 20 &&
            head[i].getPosition().x) head[i].setPosition(cur_coords[i - 1].x, head[i].getPosition().y);
    }
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
    dir = check_keyboard_key();
    if (is_int_coords()) {
        set_direction();
        update_cur_coords();
        collision(score);
    }
    movement();
}

Snake:: ~Snake() {}


void Snake:: set_direction() {
    if (dir == Direction::UP || dir == Direction::DOWN) {
        vec_y = SPEED * (dir == Direction::UP ? -1 : 1);
        vec_x = 0.00f;
    }
    if (dir == Direction::LEFT || dir == Direction::RIGHT) {
        vec_y = 0.00f;
        vec_x = SPEED * (dir == Direction::LEFT ? -1 : 1);
    }
}

bool Snake:: is_int_coords() {
    float x = head[0].getPosition().x, y = head[0].getPosition().y;
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

sf:: Vector2f Snake:: get_head_pos() {
    return head.front().getPosition();
}
