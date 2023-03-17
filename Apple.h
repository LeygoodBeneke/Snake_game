#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include "SnakeClass.h"

#define RADIUS 10

class Apple {
public:
    void draw(sf:: RenderWindow &window);
    bool is_eaten(sf:: Vector2f head_pos);
    void logic(sf::Vector2f head_pos, Snake& snake);
    Apple();
private:
    sf::CircleShape apple;
};
