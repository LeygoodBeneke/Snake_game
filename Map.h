#include <SFML/Graphics.hpp>

class Map {
public:
    Map(int n, int m, int rad=20);
    void init();
    void draw(sf:: RenderWindow &window);

private:
    std:: vector<std:: vector<int>> map;
    int radius;
};
