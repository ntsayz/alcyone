#include "Ship.h"
#include <SFML/Graphics.hpp>


int main()
{
    //CONSTANTS
    std::string PLAYER_FNAME = "resources/S001_1_36.png";
    std::string BG_FNAME = "resources/starsbg.png";
    sf::Vector2u WINDOW_SIZE(600,400);

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
        window.clear(sf::Color::Black);

        //float delta = clock.restart().asSeconds();

        window.draw(back);
        ship.update(event,WINDOW_SIZE);
        window.draw(ship.getShipSprite());
        
        // Display window contents on screen
        
        window.display();
    }

    return EXIT_SUCCESS;
}
