#include "Score.h"
#include <SFML/Graphics/RenderWindow.hpp>

enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    DEFAULT
};

class Snake {
public:
    void draw();
    void logic(Score &score);
    sf:: Vector2f get_head_pos();
    void add_body();
    Snake(int h, int w, sf::RenderWindow& win);
    ~Snake();
private:
    void set_direction();
    bool is_int_coords();
    enum Direction check_keyboard_key();
    void init_head();
    void movement();
    void update_cur_coords();
    void collision(Score &score);
    float get_motion_value(int left, int right);
    sf::Vector2f get_motion_vector(size_t idx);
    void check_head_position();
    void body_movement(int idx);
    std:: vector<sf::CircleShape> head;
    std:: vector<sf::Vector2f> cur_coords;
    Direction dir;
    float vec_x, vec_y;
    int height, width;
    sf::RenderWindow& window;
};
