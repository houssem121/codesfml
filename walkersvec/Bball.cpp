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
void BCball::update(sf::RenderWindow &window) {

    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
    sf::Vector2f mouse(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y));
    mouse = check_bounds(mouse, window);
    // std::cout<<"x:\n"<<mouse.x;
    sf::Vector2f direction = mouse - location ; //vec to mouse location sorry

    sf::Vector2f Normalized_Direction = Normalize(direction);//normalize the vector for smooth animation and

    sf::Vector2f mul_direction = Normalized_Direction * 0.1f;//take a portion from that u_n vector
    sf::Vector2f accelerations = mul_direction;

    velocity = velocity + accelerations; //set acceleration

    location = location + velocity; //set position from velocity
  //  velocity = velocity - accelerations; //like this we can stop a the mouse location if we remove it when the velocity will be huge the more get closer the position and then start to slow down
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