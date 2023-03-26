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
        int new_x = rand() % (height / 20 - 2) * 20 + 20;
        int new_y = rand() % (width / 20 - 4) * 20 + 60;
        apple.setPosition(new_x, new_y);
        snake.add_body();
        score.inc_score();
    }
}

Apple:: Apple(int h, int w) : apple(RADIUS), height(h), width(w) {
    apple.setFillColor(sf::Color::Red);
    apple.setPosition(40, 60);
}

