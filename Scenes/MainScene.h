#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

#include "../templates/Button.h"

class MainScene {
public:
    void drawScene();
    bool logic();
    MainScene(int h, int w, sf::RenderWindow& win);

private:
    int height, width;
    sf::RenderWindow &window;
    sf::RectangleShape play_button;
    Button button;
};
