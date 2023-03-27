#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <sstream>
#include <iostream>
class Button {
public:
    void draw() {
        window.draw(rect);
        window.draw(text);
    }

    Button(sf::RenderWindow& win) : font(), window(win), rect() {}

//    Button(sf::Vector2f& size, sf::Vector2f& pos, std:: string str, sf::RenderWindow& win) : font(), window(win), rect() {
//        font.loadFromFile("../fonts/Hack-Regular.ttf");
//        text = sf:: Text(str, font, 22);
//        text.setPosition(pos);
//        rect.setPosition(pos);
//        rect.setScale(size);
//    }

    void setUp(sf::Vector2f size, sf::Vector2f pos, std:: string str, std:: string Font = "fonts/Hack-Regular.ttf", int font_size=22) {
        if (!font.loadFromFile(Font)) std:: cout << "QWEQWE";
        text = sf:: Text(str, font, font_size);
        text.setPosition(pos);
        rect.setPosition(pos);
        rect.setSize(size);
        text.setFillColor(sf::Color(0,0,0));
        rect.setFillColor(sf::Color(255,255,255));
    }  

private:

    sf::Text text;
    sf::Font font;
    sf::RenderWindow &window;
    sf::RectangleShape rect;
};
