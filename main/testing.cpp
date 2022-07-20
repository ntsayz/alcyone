#include <SFML/Graphics.hpp>


int main(){
        // Create the main rendering window
    /*sf::Texture player;
    if(!player.loadFromFile("resources/S001_1_36.png")){
        return -1;
    }
    player.setSmooth(true);

    sf::Sprite playerSprite;
    playerSprite.setTexture(player);
    sf::Vector2f playerPos(300,300);
    playerSprite.setPosition(playerPos);

    float xVel = 2, yVel= 2;
*/


/*
        if(playerPos.x < 0 || playerPos.x > 600 - 62) xVel *= -1;
        if(playerPos.y < 0  || playerPos.y > 600-105) yVel *= -1;
        
        playerPos.x += xVel;
        playerPos.y += yVel;

        playerSprite.setPosition(playerPos);
        window.draw(playerSprite);

*/
}

/*
void update(RenderWindow& window) 
        {
            float decceleration = 0.3;
    
            if (Keyboard::isKeyPressed(Keyboard::W))
            {
                accelerationY -= decceleration;
            }
            if (Keyboard::isKeyPressed(Keyboard::S))
            {
                accelerationY += decceleration;
            }
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                accelerationX -= decceleration;
            }
            if (Keyboard::isKeyPressed(Keyboard::D))
            {
                accelerationX += decceleration;
            }
    
            dx += accelerationX;
            dy += accelerationY;
    
            speed = sqrt(dx * dx + dy * dy);
            if (speed > maxSpeed)
            {
                dx *= maxSpeed / speed;
                dy *= maxSpeed / speed;
            }
    
            x += dx;
            y += dy;
    
            dx *= 0.9;
            dy *= 0.9;
    
            accelerationX = 0;
            accelerationY = 0;
    
            EntitySprite.setPosition(x, y);
            window.draw(EntitySprite);
    
        }
*/
 // sf::Clock clock;
 //float delta = clock.restart().asSeconds();