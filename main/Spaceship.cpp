#include "Spaceship.h"
#include <iostream>
Spaceship::Spaceship( sf::Vector2u size){
    this->ship.setRadius(150);
    this->ship.setOutlineColor(sf::Color::Red);
    this->x = 10;
    this->y= 10;
    this->ship.setPosition(x,y);
    this->velocity.x = 0;
    this->velocity.y = 0;
    
}

void Spaceship::draw( sf::RenderWindow &window){
    window.draw(ship);
}
void Spaceship::move(sf::Event event){
    
    // adjust this at will
    const float dAcc = 0.3f;

    // set acceleration
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      acceleration.y -= dAcc;
      std::cout << event.KeyPressed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      acceleration.x -= dAcc;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      acceleration.y += dAcc;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      acceleration.x += dAcc;

    // update velocity through accelerationss
    
    // update position through velocity
    x += velocity.x;
    y += velocity.y;
    // apply damping to the velocity
    velocity = 0.99f * velocity;
    ship.setPosition(x, y);

    //window.draw(EntitySprite);

}

sf::CircleShape Spaceship::getShape(){
    return ship;
}