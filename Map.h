#include <SFML/Graphics.hpp>

class Map {
public:
    Map(int n, int m);
    void init();
    void draw(sf:: RenderWindow &window);

private:
    std:: vector<std:: vector<int>> map;
};
