#ifndef MANAGER_H
#define MANAGER_H

#include "Ship.h"
#include "Bullet.h"
#include "Utils.h"
#include <SFML/Graphics.hpp>
#include <string.h>

class Manager{
    private:
    
    public:
        void startApplication(sf::Vector2u WINDOW_SIZE);
        sf::Sprite loadBackground(std::string BG_FNAME);
        void startGame( sf::RenderWindow &window, sf::Vector2u WINDOW_SIZE);
        bool loadFiles(); //to be implemented
};


#endif 