#include <SFML/Graphics.hpp>

class Map {
public:
    Map(sf::RenderWindow& win, int rad=20);
    void init();
    void draw();

private:
    std:: vector<std:: vector<int>> map;
    sf::RenderWindow& window;
    int radius;
};
