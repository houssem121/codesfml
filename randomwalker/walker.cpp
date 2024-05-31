#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include "walker.hh"
walker::walker()
{
    x = 800 / 2;
    y = 400 / 2;
}
int walker::genRun()
{
    std::random_device rd;                         // Générateur de nombres aléatoires matériel
    std::mt19937 gen(rd());                        // Générateur de nombres pseudo-aléatoires Mersenne Twister
    std::uniform_int_distribution<> distrib(1, 6); // Distribution uniforme entre 1 et 4

    int choice = distrib(gen); // Générer le nombre aléatoire

    return choice;
}
void walker::display(sf::RenderWindow &window)
{
    std::cout << "x:" << x << "y:" << y;
    sf::Vertex point(sf::Vector2f(x, y), sf::Color::White);
    window.draw(&point, 1, sf::Points);
}
void walker::step()
{
    int choice = genRun();
    if (x <= 80 || y <= 80)
    {
        y = x = 400;
    }
    else if (choice == 0)
    {
        x++;
    }
    else if (choice == 1)
    {
        x--;
    }
    else if (choice == 2)
    {
        y--;
    }
    else
    {
        y++;
    }
}

