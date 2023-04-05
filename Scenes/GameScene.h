#include <SFML/Graphics.hpp>
#include "../Map.h"
#include "../Apple.h"
#pragma once
#include "../templates/Button.h"

class GameScene {
public:
    void drawScene();
    bool logic();
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
    Button pause_button;
    Button resume_button;
    Button main_menu_button;
};
