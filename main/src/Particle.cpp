#include "Particle.h"
#include <iostream>

Particle::Particle(sf::Vector2f position, sf::Vector2f velocity, float lifetime)
    : velocity(velocity), lifetime(lifetime) {
    // Load particle texture (1x1 pixel)
    static sf::Texture particleTexture;
    static bool textureLoaded = false;
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

void Particle::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

bool Particle::isAlive() const {
    return lifetime > 0;
}