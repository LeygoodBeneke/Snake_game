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

    Score(int height, int width) : font() {
        font.loadFromFile("fonts/Hack-Regular.ttf");
        text = sf:: Text("Scroe: ", font, 22);
        text.setPosition(height / 2.0f - 40, width * 0 + 5);
        score = 0;
    }

    void inc_score() { score++; }
    void set_score(int new_score) { score = new_score; }


private:
    sf::Text text;
    sf::Font font;
    int score;
};
