#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bball.hh"
#include <cmath>
BCball::BCball(){
    location= sf::Vector2f(400.0f, 400.0f);
    velocity=sf::Vector2f(-1/2.0f,1/2.0f);
    acceleration=sf::Vector2f(-0.01f,0.01f);
}
void BCball::update(){
    if(std::sqrt(std::pow(velocity.x,2)+std::pow(velocity.y,2))<=limite)velocity=velocity+acceleration;
    std::cout <<"velocity:"<<std::sqrt(std::pow(velocity.x,2)+std::pow(velocity.y,2));
    location=location+velocity;
    std::cout<<location.x;
}
void BCball::display(sf::RenderWindow &window)
{
    
    sf::CircleShape circle(5);
    circle.setPosition(location);
    window.draw(circle);
}
void BCball::checkEdges(){
    if(location.x>1200.0f){
        location.x=400.0f;
    }else if (location.x<0.0f){
        location.x=400.0f;
    }
     if(location.y>800.0f){
        location.y=400.0f;
    }else if (location.x<0.0f){
        location.y=400.0f;
    }

}