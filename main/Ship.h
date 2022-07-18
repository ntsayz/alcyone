#ifndef SHIP_H
#define SHIP_H
#include <SFML/Graphics.hpp>
#include <string.h>

class Ship{
    private:
        sf::Texture ship;
        sf::Sprite shipSprite;
        sf::Vector2f acceleration;
        sf::Vector2f velocity;
        sf::Vector2f VMAX;
        float x,y;
    public:
        Ship(std::string fname , sf::Vector2u size);
        void draw( sf::RenderWindow &window);
        void update(sf::Event event, sf::Vector2u wsize, sf::RenderWindow &window);
        sf::Vector2f getShip();


};


#endif