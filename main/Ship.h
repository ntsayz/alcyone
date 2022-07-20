#ifndef SHIP_H
#define SHIP_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <string.h>

class Ship{
    private:
        const int shipWidth = 50 , shipLength = 50; 
        sf::Texture ship;
        sf::Sprite shipSprite;
        sf::Vector2f acceleration, velocity, direction, FRICTIONF = {0.0f,0.0f} , VMAXv = {2.0,2.0};
        float x,y , VMAX = 2.0;
        const float FRICTION_COEF = 0.4f, dAcc = 0.02f;
    public:
        Ship(std::string fname , sf::Vector2u size);
        void draw( sf::RenderWindow &window);
        void lookAtMouse(sf::RenderWindow &window);  
        void update(sf::Event event, sf::Vector2u wsize);
        sf::Sprite const getShipSprite();
        sf::Vector2f const getShipPos();
        void showInfo() const{
            float vnorm = sqrt(pow(velocity.x,2)+pow(velocity.y,2));
            float anorm = sqrt(pow(acceleration.x,2)+pow(acceleration.y,2));
            std::cout << "Position (" << x << "," << y <<")"  << std::endl;
            std::cout << "Velocity " << vnorm << "m/s " <<  std::endl;
            std::cout << "Aceleration " << anorm << "m/s²" << std::endl;
            std::cout<< u8"\033[2J\033[1;1H" ;
        }


};


#endif