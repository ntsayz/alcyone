#ifndef SHIP_H
#define SHIP_H
#include <SFML/Graphics.hpp>
#include <string.h>

class Ship{
    private:
        const int shipWidth = 62 , shipLength = 105; 
        sf::Texture ship;
        sf::Sprite shipSprite;
        sf::Vector2f acceleration, velocity, VMAX, FRICTIONF = {0.0f,0.0f};
        float x,y;
        const float FRICTION_COEF = 0.4f, dAcc = 0.02f;
    public:
        Ship(std::string fname , sf::Vector2u size);
        void draw( sf::RenderWindow &window);
        void update(sf::Event event, sf::Vector2u wsize, sf::RenderWindow &window);
        sf::Vector2f getShip();


};


#endif