#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bball.hh"
#include <cmath>
#include "/home/kali/Desktop/codesfml/math/math.cpp"

BCball::BCball(int width,int height) {
    location = sf::Vector2f(random_location<float>(width),random_location<float>(height));
    velocity = sf::Vector2f(-1 / 2.0f, 1 / 2.0f);
    acceleration = sf::Vector2f(-0.01f, 0.01f);
}
void BCball::update() {
    if (mag(velocity) <= limite) {
        velocity = velocity + acceleration;
    }
    location = location + velocity;

}
void BCball::display(sf::RenderWindow &window)
{

    sf::CircleShape circle(5);
    circle.setPosition(location);
    window.draw(circle);
}
void BCball::checkEdges() {
    if (location.x > 1200.0f) {
        location.x = random_location<float>(1200);
    } else if (location.x < 0.0f) {
        location.x = random_location<float>(800);
    }
    if (location.y > 800.0f) {
        location.y = random_location<float>(1200);
    } else if (location.x < 0.0f) {
        location.y = random_location<float>(800);
    }

}