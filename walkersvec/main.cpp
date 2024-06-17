#include <SFML/Graphics.hpp>
#include "Bball.hh"

int main() {


    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
    std::vector<BCball> balls;
    for (int i = 0; i < 20; ++i) {
        balls.push_back(BCball(window.getSize().x, window.getSize().y));
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); // Clear the window before drawing
        for (int i = 0; i < 20; ++i) {
            balls[i].display(window);
            balls[i].update(window);
            balls[i].checkEdges();
        }

        window.display(); // Display the updated frame
    }

    // Clean up the dynamically allocated memory
    return 0;
}
