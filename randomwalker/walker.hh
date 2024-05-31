#include <SFML/Graphics.hpp>

class walker
{
    public:
    int x;
    int y;

    walker();
    int genRun();
    void display(sf::RenderWindow& window);
    void step();
};