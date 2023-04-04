#include "Map.h"

Map:: Map(sf::RenderWindow& win, int rad)
    : map(win.getSize().x / (rad * 2) , std:: vector<int>(win.getSize().y / (rad * 2) - 2)), radius(rad),
      window(win) {}

void Map:: init() {
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

void Map:: draw() {
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j] == 1) {
                sf::RectangleShape rect;
                rect.setSize(sf::Vector2f(radius * 2, radius * 2));
                rect.move(i * (radius * 2), j * (radius * 2) + 4 * (radius));
                window.draw(rect);
            }
        }
    }
}

