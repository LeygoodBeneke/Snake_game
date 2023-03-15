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
    void draw(sf:: RenderWindow &window);
    void logic(sf:: RenderWindow &window);
    Snake();
    ~Snake();
private:
    int cur_x = 0, cur_y = 0;
    sf::CircleShape *head;
    sf::CircleShape *head1;
    Direction dir;
    float vec_x, vec_y;
    void set_direction();
    bool is_int_coords();
    enum Direction check_keyboard_key();
};
