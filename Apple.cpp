#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include "Apple.h"


void Apple:: draw(sf:: RenderWindow &window) {
    window.draw(apple);
}

bool Apple:: is_eaten(sf:: Vector2f head_pos) {
    return int(head_pos.x) == int(apple.getPosition().x) &&
           int(head_pos.y) == int(apple.getPosition().y);
}

void Apple:: logic(sf::Vector2f head_pos, Snake& snake) {
    if (is_eaten(head_pos)) {
        int new_x = rand() % 50 * 20;
        int new_y = rand() % 50 * 10;
        apple.setPosition(new_x, new_y);
        snake.add_body();
    }
}

Apple:: Apple() {
    apple = sf::CircleShape(RADIUS);
    apple.setFillColor(sf::Color::Red);
    apple.setPosition(40, 60);
}

