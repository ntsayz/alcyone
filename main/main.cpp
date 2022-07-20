#include "Ship.h"
#include <SFML/Graphics.hpp>


int main()
{
    //CONSTANTS
    std::string PLAYER_FNAME = "resources/triangle.png";
    std::string BG_FNAME = "resources/starsbg.png";
    sf::Vector2u WINDOW_SIZE(800,800);

    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "A");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);


    Ship ship(PLAYER_FNAME, WINDOW_SIZE);

    sf::Texture tex;
    if(!tex.loadFromFile(BG_FNAME)){
        return -1;
    }

    sf::Sprite back(tex);


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
                case sf::Event::KeyReleased:
                        //ship.update(event,WINDOW_SIZE);
                        break;
                default:
                    break;
            }
        }

        // Clear the screen
        window.clear(sf::Color::White);

        //float delta = clock.restart().asSeconds();

        //window.draw(back);


        ship.update(event,WINDOW_SIZE);
        //ship.lookAtMouse(window); //very complicated bugs
        window.draw(ship.getShipSprite());
        
        // Display window contents on screen
        
        window.display();
    }

    return EXIT_SUCCESS;
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