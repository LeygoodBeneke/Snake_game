#include "SnakeClass.h"

class Apple {
public:
    void draw(sf:: RenderWindow &window);
    bool is_eaten(sf:: Vector2f head_pos);
    void logic(Snake& snake, Score &score);
    Apple(int h, int w, int rad=20);
private:
    sf::CircleShape apple;
    int height, width;
    int radius;
};
