#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <sstream>
#include <iostream>
class Button {
public:
    void draw() {
        window.draw(sprite);
        hover();
    }

    Button(sf::RenderWindow& win) : window(win) {}

    void setUp(sf::Vector2f pos, std::string filename) {
        texture.loadFromFile(filename);
        sprite.setTexture(texture);
        sprite.setPosition(pos);
    }

    bool isPressed() {
        if (sprite.getPosition().x <= sf::Mouse::getPosition(window).x && sf::Mouse::getPosition(window).x <= sprite.getPosition().x + sprite.getGlobalBounds().width &&
            sprite.getPosition().y <= sf::Mouse::getPosition(window).y && sf::Mouse::getPosition(window).y <= sprite.getPosition().y + sprite.getGlobalBounds().height) {
            if (sf:: Mouse::isButtonPressed(sf::Mouse::Left)) return true;
        }
        return false;
    }

    sf::Vector2f getScale() {
        return sprite.getScale();
    }


private:
    void hover() {
        if (sprite.getPosition().x <= sf::Mouse::getPosition(window).x && sf::Mouse::getPosition(window).x <= sprite.getPosition().x + sprite.getGlobalBounds().width &&
            sprite.getPosition().y <= sf::Mouse::getPosition(window).y && sf::Mouse::getPosition(window).y <= sprite.getPosition().y + sprite.getGlobalBounds().height) {
            sprite.setColor(sf::Color(189, 147, 249));
        } else sprite.setColor(sf::Color(248, 248, 242));
    }

    sf::RenderWindow &window;
    sf::Texture texture;
    sf::Sprite sprite;
};
