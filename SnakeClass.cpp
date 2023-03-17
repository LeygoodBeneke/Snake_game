#include "SnakeClass.h"

#define INIT_SIZE 5
#define RADIUS 10

void Snake:: draw(sf:: RenderWindow &window) {
    for (int i = 0; i < INIT_SIZE; i++) window.draw(head[i]);
    //window.draw(*head1);
}

void Snake:: init_head(std:: vector<sf::CircleShape>& h, std:: vector<sf::Vector2f>& cc) {
    for (int i = 0; i < INIT_SIZE; i++) {
        h.push_back(sf::CircleShape(RADIUS));
        h.back().setFillColor(sf::Color::Green);
        h.back().move(80.0f + 20.0f * (i != 0), 100.0f);
        cc.push_back(sf::Vector2f(0.0f, 0.0f));
    }
}

Snake:: Snake() {
    vec_x = 1.0f;
    vec_y = 0.00f;
    dir = DEFAULT;
    init_head(head, cur_coords);
    head1 = new sf::CircleShape(RADIUS);
    head1->setFillColor(sf::Color::Green);
    cur_coords.push_back(sf::Vector2f(0.0f, 0.0f));
    cur_coords.push_back(sf::Vector2f(0.0f, 0.0f));
}

void Snake:: logic(sf:: RenderWindow &window) {
    draw(window);
    dir = check_keyboard_key();
    if (is_int_coords()) {
        set_direction();
        cur_x = head[0].getPosition().x, cur_y = head[0].getPosition().y;

        for (int i = 0; i < INIT_SIZE; i++) {
            cur_coords[i] = head[i].getPosition();
        }
    }
    head[0].move(vec_x, vec_y);
    for (int i = 1; i < INIT_SIZE; i++) {
        if (int(cur_coords[i - 1].x) > int(head[i].getPosition().x)) head[i].move(1.f, 0);
        else if (int(cur_coords[i - 1].y) > int(head[i].getPosition().y)) head[i].move(0, 1.f);
        else if (int(cur_coords[i - 1].x) < int(head[i].getPosition().x)) head[i].move(-1.f, 0);
        else if (int(cur_coords[i - 1].y) < int(head[i].getPosition().y)) head[i].move(0, -1.f);
    }
}

Snake:: ~Snake() {
    delete head1;
}


void Snake:: set_direction() {
    if (dir == Direction::UP) {
        vec_y = -1.f;
        vec_x = 0.00f;
    }
    if (dir == Direction::DOWN) {
        vec_y = 1.f;
        vec_x = 0.00f;
    }
    if (dir == Direction::LEFT) {
        vec_y = 0.00f;
        vec_x = -1.f;
    }
    if (dir == Direction::RIGHT) {
        vec_y = 0.00f;
        vec_x = 1.f;
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
    return head[0].getPosition();
}
