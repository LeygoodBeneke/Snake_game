#include "Score.h"
#include <SFML/Graphics/RenderWindow.hpp>


class Snake {
public:
    void draw();
    void logic(Score &score);
    sf:: Vector2f get_head_pos();
    void add_body();
    void set_keyboard_key(sf::Keyboard::Key key);
    Snake(sf::RenderWindow& win, int rad=20, float spd=10.0f);
    ~Snake();
private:
    void set_direction();
    bool is_int_coords();
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
    sf::Keyboard::Key dir;
    float vec_x, vec_y;
    sf::RenderWindow& window;
    int radius;
    float speed;
};
