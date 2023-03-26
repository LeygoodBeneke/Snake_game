#include "Map.h"


Map:: Map(int n, int m) : map(n, std:: vector<int>(m)) {}

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

void Map:: draw(sf:: RenderWindow &window) {
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

