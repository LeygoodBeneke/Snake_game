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
        text.setPosition(height / 2.0f - text.getString().getSize() * 22 / 3.0, width * 0 + 5);
        window.draw(text);
    }

    Score(int h, int w) : font(), height(h), width(w) {
        font.loadFromFile("fonts/Hack-Regular.ttf");
        text = sf:: Text("Scroe: ", font, 22);
        text.setPosition(height / 2.0f - text.getString().getSize() * 22 / 3.0, width * 0 + 5);
        score = 0;
    }

    void inc_score() { score++; }
    void set_score(int new_score) { score = new_score; }


private:
    sf::Text text;
    sf::Font font;
    int score, height, width;
};
