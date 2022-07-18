#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <SFML/Graphics.hpp>

class Spaceship{
    private:
        sf::CircleShape ship;
        sf::Vector2f acceleration;
        sf::Vector2f velocity;
        float x,y;
    public:
        Spaceship( sf::Vector2u size);
        void draw( sf::RenderWindow &window);
        void move(sf::Event event);

        sf::CircleShape getShape();


};


#endif