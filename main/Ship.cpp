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

    }

void Ship::draw(sf::RenderWindow &window){
  window.draw(shipSprite);
}
void Ship::update(sf::Event event, sf::Vector2u wsize){
    
    // adjust this at will
    const float dAcc = 0.3f;

    // set acceleration
    //
    if (sf::Keyboard::Key::W == event.key.code)
      acceleration.y -= dAcc;
    if (sf::Keyboard::Key::A == event.key.code)
      acceleration.x -= dAcc;
    if (sf::Keyboard::Key::S == event.key.code)
      acceleration.y += dAcc;
    if (sf::Keyboard::Key::D == event.key.code)
      acceleration.x += dAcc;

    // update velocity through accelerationss
    velocity += acceleration;

    if(x < 0 || x > wsize.x - 62) velocity.x *=-1;
    if(y < 0 || y > wsize.y -105) velocity.y *=-1;
    // update position through velocity
    x += velocity.x;
    y += velocity.y;

    if(x < 0 || x > wsize.x - 62) velocity.x *=-1;x += velocity.x ;
    if(y < 0 || y > wsize.y -105) velocity.y *=-1;y += velocity.y;
    // apply damping to the velocity
    velocity = 0.99f * velocity;
    shipSprite.setPosition(x, y);

}

sf::Vector2f Ship::getShip(){
    return shipSprite.getPosition();
}