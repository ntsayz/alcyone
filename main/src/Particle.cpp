#include "Particle.h"
#include <iostream>

sf::Texture Particle::particleTexture;
bool Particle::textureLoaded = false;

// Particle class implementation
Particle::Particle(sf::Vector2f position, sf::Vector2f velocity, float lifetime)
    : velocity(velocity), lifetime(lifetime) {
    if (!textureLoaded) {
        if (!particleTexture.loadFromFile("particle.png")) {
            std::cerr << "Failed to load particle.png" << std::endl;
        }
        textureLoaded = true;
    }
    sprite.setTexture(particleTexture);
    sprite.setPosition(position);
}

void Particle::update(float deltaTime) {
    lifetime -= deltaTime;
    sprite.move(velocity * deltaTime);
}

void Particle::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

bool Particle::isAlive() const {
    return lifetime > 0;
}