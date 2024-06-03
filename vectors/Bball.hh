#include <SFML/Graphics.hpp>

class BCball{
    sf::Vector2f location;
    sf::Vector2f velocity;
    public:
    BCball();
    void update();
    void display(sf::RenderWindow &window);
    void checkEdges();
};