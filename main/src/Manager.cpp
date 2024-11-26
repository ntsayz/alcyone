#include "Manager.h"

void Manager::startApplication(sf::Vector2u WINDOW_SIZE){

    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "unnamed untitled");
    window.setVerticalSyncEnabled(true);  //sync to monitor's refresh rate
    window.setFramerateLimit(60);
    startGame(window, WINDOW_SIZE);

}


void Manager::startGame(sf::RenderWindow &window, sf::Vector2u WINDOW_SIZE) {
    Utils &utils = Utils::getInstance();
    std::string PLAYER_FNAME = utils.getResourcePath("rectangle.png");

    Ship ship(PLAYER_FNAME, WINDOW_SIZE);
    sf::Clock deltaClock;

    while (window.isOpen()) {
        float deltaTime = deltaClock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ship.update(event,WINDOW_SIZE,deltaTime);
        ship.updateParticles(deltaTime);           // Keep particle updates separate
        window.clear(sf::Color::White);
        ship.draw(window);
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