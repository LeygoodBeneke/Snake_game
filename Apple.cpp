#include "Apple.h"

void Apple:: draw(sf:: RenderWindow &window) {
    window.draw(apple);
}

bool Apple:: is_eaten(sf:: Vector2f head_pos) {
    return int(head_pos.x) == int(apple.getPosition().x) &&
           int(head_pos.y) == int(apple.getPosition().y);
}

void Apple:: logic(Snake& snake, Score& score) {
    if (is_eaten(snake.get_head_pos())) {
        int new_x = rand() % (height / (2 * radius) - 2) * (2 * radius) + radius * 2;
        int new_y = rand() % (width / (2 * radius) - 4) * (2 * radius) + radius * 6;
        apple.setPosition(new_x, new_y);
        snake.add_body();
        score.inc_score();
    }
}

Apple:: Apple(int h, int w, int rad) : apple(rad), height(h), width(w), radius(rad) {
    apple.setFillColor(sf::Color::Red);
    apple.setPosition(4 * radius, 6 * radius);
}

