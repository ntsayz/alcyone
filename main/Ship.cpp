#include "Ship.h"



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
    
    // set acceleration
    if (sf::Keyboard::Key::W == event.key.code || sf::Keyboard::Key::Up == event.key.code)
      acceleration.y -= dAcc;
    if (sf::Keyboard::Key::A == event.key.code || sf::Keyboard::Key::Left == event.key.code)
      acceleration.x -= dAcc;
    if (sf::Keyboard::Key::S == event.key.code || sf::Keyboard::Key::Down == event.key.code)
      acceleration.y += dAcc;
    if (sf::Keyboard::Key::D == event.key.code || sf::Keyboard::Key::Right == event.key.code)
      acceleration.x += dAcc;

    // Collision with window bounds
    // takes in account size of the texture
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

    //changing velocity with acceleration and force of friction

    //when I change the condition to make it more readable, it stops working 
    if(abs(velocity.x) > VMAXv.x || abs(velocity.y) > VMAXv.y){
    }else{
      velocity += acceleration;
    }
    FRICTIONF = FRICTION_COEF * velocity;
    velocity -= FRICTIONF;

    
    // update position through velocity 
    x += velocity.x;
    y += velocity.y;

    showInfo();
    shipSprite.setPosition(x, y);


}



void Ship::lookAtMouse(sf::RenderWindow &window){
    sf::Vector2f curPos = shipSprite.getPosition();
    sf::Vector2i position = sf::Mouse::getPosition(window);

    // now we have both the sprite position and the cursor
    // position lets do the calculation so our sprite will
    // face the position of the mouse
    const float PI = 3.14159265;

    float dx = curPos.x - position.x;
    float dy = curPos.y - position.y;

    float rotation = (atan2(dy, dx)) * 180 / PI;

    shipSprite.setRotation(rotation + 180);

}

sf::Vector2f const Ship::getShipPos(){
    return shipSprite.getPosition();
}
sf::Sprite const Ship::getShipSprite(){
  return shipSprite;
}