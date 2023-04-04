#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

#include "../templates/Button.h"

class MainScene {
public:
    void drawScene();
    bool logic();
    MainScene(sf::RenderWindow& win);

private:
    sf::RenderWindow &window;
    Button play_button, settings_button, exit_button;
};
