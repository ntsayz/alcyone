#include "Spaceship.h"
#include <SFML/Graphics.hpp>

int main()
{

    sf::RenderWindow window(sf::VideoMode(600, 600), "Test");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    // Create the main rendering window
    sf::Texture player;
    if(!player.loadFromFile("resources/S001_1_36.png")){
        return -1;
    }
    player.setSmooth(true);

    sf::Sprite playerSprite;
    playerSprite.setTexture(player);
    sf::Vector2f playerPos(300,300);
    playerSprite.setPosition(playerPos);

    float xVel = 2, yVel= 2;
    



    while (window.isOpen()){

        
    // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                            //xVel +=2 ;
                            //playerPos.x -= xVel;
                        }
                        break;
                case sf::Event::KeyReleased:
                default:
                    break;
            }
        }
        // Clear the screen
        window.clear(sf::Color::Black);

        if(playerPos.x < 0 || playerPos.x > 600 - 62) xVel *= -1;
        if(playerPos.y < 0  || playerPos.y > 600-105) yVel *= -1;
        
        playerPos.x += xVel;
        playerPos.y += yVel;

        playerSprite.setPosition(playerPos);
    
        window.draw(playerSprite);

        // Display window contents on screen
        window.display();
    }

    return EXIT_SUCCESS;
}
