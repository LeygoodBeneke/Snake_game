#include "SnakeClass.h"

#define RADIUS 20

class Apple {
public:
    void draw(sf:: RenderWindow &window);
    bool is_eaten(sf:: Vector2f head_pos);
    void logic(Snake& snake, Score &score);
    Apple(int h, int w);
private:
    sf::CircleShape apple;
    int height, width;
};
