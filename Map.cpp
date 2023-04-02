#include "Map.h"
#define RADIUS 20

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
                sf::Vector2f vec = {RADIUS * 2, RADIUS * 2};
                rect.setSize(vec);
                rect.move(i * (RADIUS * 2), j * (RADIUS * 2) + 4 * (RADIUS));
                window.draw(rect);
            }
        }
    }
}

