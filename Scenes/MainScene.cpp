#include "MainScene.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

void MainScene:: drawScene() {
    play_button.draw();
    settings_button.draw();
    exit_button.draw();
}

bool MainScene:: logic() {
    if (exit_button.isPressed()) window.close();
    return play_button.isPressed();
}


MainScene:: MainScene(sf::RenderWindow& win) : window(win), play_button(win), settings_button(win), exit_button(win)  {
    play_button.setUp(sf:: Vector2f(window.getSize().x / 2.f - 101.5, window.getSize().y / 2.f), "Images/PlayButton.png");
    settings_button.setUp(sf:: Vector2f(window.getSize().x / 2.f - 185.5, window.getSize().y / 2.f + 90), "Images/SettingsButton.png");
    exit_button.setUp(sf:: Vector2f(window.getSize().x / 2.f - 101.5, window.getSize().y / 2.f + 180), "Images/ExitButton.png");
}
