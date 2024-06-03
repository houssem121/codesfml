#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bball.hh"

BCball::BCball(){
    location= sf::Vector2f(400.0f, 400.0f);
    velocity=sf::Vector2f(-1/2.0f,1/2.0f);
}
void BCball::update(){
    location=location+velocity;
    std::cout<<location.x;
}
void BCball::display(sf::RenderWindow &window)
{
    //std::cout << "x:" << location.x << "y:" << location.y;
    sf::Vertex point(location, sf::Color::White);
    window.draw(&point, 1, sf::Points);
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