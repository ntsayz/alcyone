#include "Manager.h"

void Manager::startApplication(sf::Vector2u WINDOW_SIZE){

    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "shoot");
    window.setVerticalSyncEnabled(true);  //sync to monitor's refresh rate
    window.setFramerateLimit(60);
    startGame(window, WINDOW_SIZE);

}


void Manager::startGame(sf::RenderWindow &window ,sf::Vector2u WINDOW_SIZE){
    //FILES TO LOAD
    std::string PLAYER_FNAME = "resources/triangle.png";
    std::string BG_FNAME = "resources/starsbg.png";

    Ship ship(PLAYER_FNAME, WINDOW_SIZE);
    
    while (window.isOpen()){
    // process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }

        // Clear the screen
        window.clear(sf::Color::White);

        ship.update(event,WINDOW_SIZE);
        window.draw(ship.getShipSprite());
        
        // display window contents on screen
        window.display();
    }
    

    

}

sf::Sprite Manager::loadBackground(std::string BG_FNAME){
    sf::Texture bgTexture;
    if(!bgTexture.loadFromFile(BG_FNAME)){
        std::cout << "Couldn't load bg file" << std::endl;
    }
    sf::Sprite bgSprite(bgTexture);
    return bgSprite;
}

bool Manager::loadFiles(){
    return false;
}