#include "Apple.h"
#include <SFML/System/Vector2.hpp>

void event_logic(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

class Map {
public:

    Map(int n, int m) : map(n, std:: vector<int>(m)) {}

    void init() {
        int m = map[0].size();
        for (size_t i = 0; i < map.size(); i++) {
            map[i][0] = 1;
            map[i][m - 1] = 1;
        }
        for (int j = 0; j < m; j++) {
            map[0][j] = 1;
            map[map.size() - 1][j] = 1;
        }
    }

    void draw(sf:: RenderWindow &window) {
        for (size_t i = 0; i < map.size(); i++) {
            for (size_t j = 0; j < map[i].size(); j++) {
                if (map[i][j] == 1) {

                    sf::RectangleShape rect;
                    sf::Vector2f vec = {20.f, 20.f};
                    rect.setSize(vec);
                    rect.move(i * 20, j * 20 + 40);
                    window.draw(rect);

                }
            }
        }
    }

private:
    std:: vector<std:: vector<int>> map;
};

void show_fps(sf:: Clock& clock) {
    float curr_time = clock.restart().asSeconds();
    float fps = 1.0f / curr_time;
    std:: cout << "fps: " << fps << '\n';
}

void game() {
    int h = 400, w = 300;
    sf::RenderWindow window(sf::VideoMode(h, w), "Snake");
    Snake snake(h, w);
    Apple apple(h, w);
    Score score(h, w);
    Map map(h / 20, w / 20 - 2);
    map.init();

    sf::Clock clock;
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        show_fps(clock);
        event_logic(window);
        window.clear();
        snake.logic(window, score);
        apple.logic(snake, score);

        score.draw(window);
        map.draw(window);
        apple.draw(window);
        window.display();
    }
}

int main() {
    game();
    return 0;
}

