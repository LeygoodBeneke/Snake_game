#include "MainScene.h"
#include <SFML/System/Vector2.hpp>

void MainScene:: drawScene() {
    button.draw();
}

bool MainScene:: logic() {
    return  button.isPressed();
}


MainScene:: MainScene(int h, int w, sf::RenderWindow& win) : height(h), width(w), window(win), play_button(sf::Vector2f(0, 0)), button(win)  {
    button.setUp(sf:: Vector2f(100, 50), sf:: Vector2f(100, 50), "Hello");
}
