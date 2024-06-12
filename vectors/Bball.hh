#include <SFML/Graphics.hpp>

class BCball{
    sf::Vector2f location;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;//added new var
    int limite = 5;
    public:
    BCball();
    void update();
    void display(sf::RenderWindow &window);
    void checkEdges();
};