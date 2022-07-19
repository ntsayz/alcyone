#include "Ship.h"
#include <iostream>
#include <string.h>


Ship::Ship(std::string fname, sf::Vector2u size){

    if(!ship.loadFromFile(fname)){

    }
    ship.setSmooth(true);
    shipSprite.setTexture(ship);
    x = size.x/2;
    y = size.y/2;
    sf::Vector2f playerPos(x,y);
    shipSprite.setPosition(playerPos);
    VMAX.x = 2;
    VMAX.y = 2;

    }

void Ship::draw(sf::RenderWindow &window){
  window.draw(shipSprite);
}
void Ship::update(sf::Event event, sf::Vector2u wsize, sf::RenderWindow &window){
    
    // set acceleration
    if (sf::Keyboard::Key::W == event.key.code)
      acceleration.y -= dAcc;
    if (sf::Keyboard::Key::A == event.key.code)
      acceleration.x -= dAcc;
    if (sf::Keyboard::Key::S == event.key.code)
      acceleration.y += dAcc;
    if (sf::Keyboard::Key::D == event.key.code)
      acceleration.x += dAcc;

    // Collision with window bounds
    
    sf::Vector2f reset;
    if(x <= 0){
      x = 0;
      reset = {x,y};
      velocity.x *=-1;
      acceleration.x = 0;
      shipSprite.setPosition(reset);
    }
    else if(x >= wsize.x - shipWidth){
      x = wsize.x - shipWidth;
      reset = {x,y};
      velocity.x *=-1;
      acceleration.x = 0;
      shipSprite.setPosition(reset);
    }
    if(y <= 0){
      y = 0;
      reset = {x,y};
      velocity.y *=-1;
      acceleration.y = 0;
      shipSprite.setPosition(reset);
    }
    else if(y >= wsize.y - shipLength){
      y = wsize.y - shipLength;
      reset = {x,y};
      velocity.y *=-1;
      acceleration.y = 0;
      shipSprite.setPosition(reset);
      
    }

    //changing velocity with acceleration and friction force

    velocity += acceleration;
    FRICTIONF = FRICTION_COEF * velocity;
    velocity -= FRICTIONF;

    
    // update position through velocity 
    x += velocity.x;
    y += velocity.y;

    
    std::cout << x << " x " << y << "  y" << std::endl;
    std::cout << velocity.x << " VelX " << velocity.y << " Vel Y" << std::endl;


    shipSprite.setPosition(x, y);

    window.draw(shipSprite);

}

sf::Vector2f Ship::getShip(){
    return shipSprite.getPosition();
}