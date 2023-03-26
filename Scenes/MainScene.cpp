#include "MainScene.h"
#include <SFML/System/Vector2.hpp>

void MainScene:: drawScene() {
    window.draw(play_button);
}

bool MainScene:: logic() {
    int btn_pos_x = play_button.getPosition().x, btn_pos_y = play_button.getPosition().y;
    int mouse_pos_x = sf::Mouse::getPosition(window).x, mouse_pos_y = sf::Mouse::getPosition(window).y;

    if (btn_pos_x <= mouse_pos_x && mouse_pos_x <= btn_pos_x + play_button.getSize().x &&
        btn_pos_y <= mouse_pos_y && mouse_pos_y <= btn_pos_y + play_button.getSize().y) {
        play_button.setFillColor(sf::Color::Blue);
        if (sf:: Mouse::isButtonPressed(sf::Mouse::Left)) {
            return true;
        }
    } else {
        play_button.setFillColor(sf::Color::Red);
    }
    return false;
}


MainScene:: MainScene(int h, int w, sf::RenderWindow& win) : height(h), width(w), window(win), play_button(sf::Vector2f(0, 0)) {
    play_button.setSize(sf::Vector2f(height / 4.0f, width / 10.0f));
    play_button.setPosition(height / 2.0f - play_button.getSize().x / 2, width / 2.0f - play_button.getSize().y / 2);
    play_button.setFillColor(sf::Color::Cyan);
}
