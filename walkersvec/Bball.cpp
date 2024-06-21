#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bball.hh"
#include <cmath>
#include "/home/kali/Desktop/codesfml/math/math.cpp"


BCball::BCball(int width, int height) {
    location = sf::Vector2f(random_location<float>(width), random_location<float>(height));
    velocity = sf::Vector2f(0.0f, 0.0f);
    acceleration = sf::Vector2f(0.0f, 0.0f);
}
void BCball::update(sf::RenderWindow &window, float dt) {

    // Get the mouse position
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
    sf::Vector2f mouse(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y));
    mouse = check_bounds(mouse, window);

    // Calculate direction to mouse
    sf::Vector2f direction = mouse - location;
    sf::Vector2f Normalized_Direction = Normalize(direction);
    sf::Vector2f mul_direction = Normalized_Direction  *  100.0f ;
    sf::Vector2f accelerations = mul_direction;

    // Update velocity and position using dt
    velocity += accelerations * dt; //dt is 1/60 so its very small variation
    location += velocity * dt + accelerations * dt * dt * 0.5f ;


}
void BCball::display(sf::RenderWindow &window)
{

    sf::CircleShape circle(5);
    circle.setPosition(location);
    window.draw(circle);
}
void BCball::checkEdges() {
    if (location.x > 1200.0f) {
        location.x = 0;
    } else if (location.x < 0.0f) {
        location.x = 0;
    }
    if (location.y > 800.0f) {
        location.y = 0;
    } else if (location.x < 0.0f) {
        location.y = 0;
    }

}
