#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.h"
#include "Particle.h"

class Ship {
private:
    const unsigned int shipWidth = 50, shipLength = 50; // Asset size
    sf::Texture ship;
    sf::Sprite shipSprite;
    Bullet bullet(std::string fname);

    sf::Vector2f acceleration = sf::Vector2f(0.0f, 0.0f);
    sf::Vector2f velocity = sf::Vector2f(0.0f, 0.0f);
    sf::Vector2f FRICTIONF = sf::Vector2f(0.0f, 0.0f);
    sf::Vector2f VMAXv = sf::Vector2f(2.0f, 2.0f);
    float x, y;

    const float FRICTION_COEF = 0.4f, dAcc = 0.02f;
    const float ROTATION_LIMIT = 0.05f, ROTATION_RATE = 0.06f;
    const float PARTICLE_SPEED = 100.0f, PARTICLE_LIFETIME = 1.0f;

    std::vector<Particle> particles;

    // Helper methods for better structure
    void handleKeyPress(sf::Event event, float rotationRad, sf::Vector2f forwardDirection, sf::Vector2f rightDirection);
    void handleCollision(sf::Vector2u wsize);

public:
    Ship(std::string fname, sf::Vector2u size);
    void update(sf::Event event, sf::Vector2u wsize, float deltaTime);
    void draw(sf::RenderWindow &window);
    void updateParticles(float deltaTime);
    void lookAtMouse(sf::RenderWindow &window);
    sf::Sprite const getShipSprite();
    sf::Vector2f const getShipPos();

    void showInfo() const {
        float vnorm = sqrt(pow(velocity.x, 2) + pow(velocity.y, 2));
        float anorm = sqrt(pow(acceleration.x, 2) + pow(acceleration.y, 2));
        std::cout << "Position (" << x << ", " << y << ")" << std::endl;
        std::cout << "Velocity " << vnorm << "m/s" << std::endl;
        std::cout << "Acceleration " << anorm << "m/s²" << std::endl;
    }
};

#endif