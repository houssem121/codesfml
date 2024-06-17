#include <SFML/Graphics.hpp>
#include "Bball.hh"

int main() {
    BCball *b = new BCball(1200,800);
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); // Clear the window before drawing
        b->display(window);
        b->update();
        b->checkEdges();
        window.display(); // Display the updated frame
    }

      // Clean up the dynamically allocated memory
    return 0;
}
