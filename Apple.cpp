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
        int new_x = rand() % (height / (2 * RADIUS) - 2) * (2 * RADIUS) + RADIUS * 2;
        int new_y = rand() % (width / (2 * RADIUS) - 4) * (2 * RADIUS) + RADIUS * 6;
        apple.setPosition(new_x, new_y);
        snake.add_body();
        score.inc_score();
    }
}

Apple:: Apple(int h, int w) : apple(RADIUS), height(h), width(w) {
    apple.setFillColor(sf::Color::Red);
    apple.setPosition(4 * RADIUS, 6 * RADIUS);
}

