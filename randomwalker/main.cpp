#include <SFML/Graphics.hpp>
#include "walker.hh"
int main()
{
    walker *w = new walker();
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        w->step();
        w->display(window);
        window.display();
    }

    return 0;
}