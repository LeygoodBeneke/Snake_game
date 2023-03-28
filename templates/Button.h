#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <sstream>
#include <iostream>
class Button {
public:
    void draw() {
        window.draw(rect);
        window.draw(text);
        hover();
    }

    Button(sf::RenderWindow& win) : font(), window(win), rect() {}

    void setUp(sf::Vector2f size, sf::Vector2f pos, std:: string str, std:: string Font = "fonts/Hack-Regular.ttf", int font_size=28) {
        if (!font.loadFromFile(Font)) std:: cout << "Font error";
        text = sf:: Text(str, font, font_size);
        rect.setSize(size);
        text.setPosition(pos.x + (rect.getSize().x / 2.0f - text.getGlobalBounds().width / 1.95f), pos.y + font_size / 4.5f);
        rect.setPosition(pos);
        text.setFillColor(sf::Color(0,0,0));
        rect.setFillColor(sf::Color(255,255,255));
    }

    bool isPressed() {
        if (rect.getPosition().x <= sf::Mouse::getPosition().x && sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
            rect.getPosition().y <= sf::Mouse::getPosition().y && sf::Mouse::getPosition(window).y<= rect.getPosition().y + rect.getSize().y) {
            if (sf:: Mouse::isButtonPressed(sf::Mouse::Left)) return true;
        }
        return false;
    }

private:
    void hover() {
        if (rect.getPosition().x <= sf::Mouse::getPosition(window).x && sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
            rect.getPosition().y <= sf::Mouse::getPosition(window).y && sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y) {
            rect.setFillColor(sf::Color::Blue);
        } else rect.setFillColor(sf::Color::White);
    }

    sf::Text text;
    sf::Font font;
    sf::RenderWindow &window;
    sf::RectangleShape rect;
};
