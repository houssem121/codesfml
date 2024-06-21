#include <SFML/Graphics.hpp>
#include "Bball.hh"

int main() {


    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
    std::vector<BCball> balls;
    sf::Clock clock;
    const float timeStep = 1.0f / 60.0f;  // Fixed time step (e.g., 60 updates per second)
    float accumulator = 0.0f;
    for (int i = 0; i < 20; ++i) {
        balls.push_back(BCball(window.getSize().x, window.getSize().y));
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float frameTime = clock.restart().asSeconds();
        accumulator += frameTime;

        // Update the ball's position with fixed time step


        window.clear(); // Clear the window before drawing
        while (accumulator >= timeStep) {//this will make the acc to be 1/60 seconds fixing dt=1/60
            for (int i = 0; i < 20; ++i) {
                balls[i].update(window, timeStep);
                balls[i].checkEdges();
            }
            accumulator -= timeStep;
        }
        for (int i = 0; i < 20; ++i) {
            balls[i].display(window);
        }
        window.display(); // Display the updated frame
    }

    // Clean up the dynamically allocated memory
    return 0;
}
