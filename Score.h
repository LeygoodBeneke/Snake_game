#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <bits/stdc++.h>

class Score {
public:
    void draw(sf::RenderWindow &window) {
        std::stringstream stream;
        stream << "Score: " << score;
        text.setString(stream.str());
        window.draw(text);
    }

    Score() {
        font = sf:: Font();
        font.loadFromFile("fonts/Hack-Regular.ttf");
        text = sf:: Text("Scroe: ", font, 22);
        text.setPosition(30, 30);
        score = 0;
    }

    void inc_score() { score++; }


private:
    sf::Text text;
    sf::Font font;
    int score;
};
