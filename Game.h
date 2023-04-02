#include "Scenes/MainScene.h"
#include "Scenes/GameScene.h"
#define WIDTH 400
#define HEIGHT 400

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
