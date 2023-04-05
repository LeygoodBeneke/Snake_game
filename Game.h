#include "Scenes/MainScene.h"
#define WIDTH 800
#define HEIGHT 800

class Game {
public:
    Game();
    void event_logic();
    void logic();

private:
    sf::RenderWindow window;
    MainScene main_scene;
    GameScene game_scene;
};
