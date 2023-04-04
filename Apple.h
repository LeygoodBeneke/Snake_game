#include "SnakeClass.h"

class Apple {
public:
    void draw(sf:: RenderWindow &window);
    bool is_eaten(sf:: Vector2f head_pos);
    void logic(Snake& snake, Score &score);
    Apple(sf::RenderWindow& win, int rad=20);
private:
    sf::CircleShape apple;
    sf::RenderWindow& window;
    int radius;
};
