#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class Ship {
public:
    Ship(const std::string& filename, const sf::Vector2u& windowSize);
    void handleInput();
    void update(float deltaTime, const sf::Vector2u& windowSize);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;
    const sf::Sprite& getSprite() const;

private:
    sf::Texture shipTexture;
    sf::Sprite shipSprite;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float rotationSpeed;
    float maxSpeed;
    float accelerationRate;
    float frictionCoefficient;
};

#endif // SHIP_H