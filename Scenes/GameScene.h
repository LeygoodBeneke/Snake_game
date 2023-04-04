#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include "../Map.h"
#include "../Apple.h"

class GameScene {
public:
    void drawScene();
    void logic();
    GameScene(sf::RenderWindow& win, int rad=20);
    void event_logic(sf::Keyboard::Key key);

private:
    sf::RenderWindow &window;
    Snake snake;
    Apple apple;
    Score score;
    Map map;
    bool isPaused = false;
    sf::Event event;
};
