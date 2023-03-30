#include "MainScene.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

void MainScene:: drawScene() {
    play_button.draw();
    exit_button.draw();
}

bool MainScene:: logic() {
    return play_button.isPressed();
}


MainScene:: MainScene(int h, int w, sf::RenderWindow& win) : height(h), width(w), window(win), play_button(win), exit_button(win)  {
    play_button.setUp(sf:: Vector2f(height / 2.f, width / 2.f));
    exit_button.setUp(sf:: Vector2f(height / 2.f, width / 2.f + 150));
}
