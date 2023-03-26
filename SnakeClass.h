#include "Score.h"

enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    DEFAULT
};

class Snake {
public:
    void draw(sf:: RenderWindow &window);
    void logic(sf:: RenderWindow &window, Score &score);
    sf:: Vector2f get_head_pos();
    void add_body();
    Snake(int h, int w);
    ~Snake();
private:
    std:: vector<sf::CircleShape> head;
    std:: vector<sf::Vector2f> cur_coords;
    Direction dir;
    float vec_x, vec_y;
    void set_direction();
    bool is_int_coords();
    enum Direction check_keyboard_key();
    void init_head();
    void movement();
    void update_cur_coords();
    void collision(Score &score);
    int height, width;
};
