#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

class MainScene {
public:
    void drawScene(sf::RenderWindow& window);
    bool logic();
    MainScene(int h, int w, sf::RenderWindow& win);

private:
    int height, width;
    sf::RenderWindow &window;
    sf::RectangleShape play_button;
};
