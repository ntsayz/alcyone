#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle {
public:
    Particle(sf::Vector2f position, sf::Vector2f velocity, float lifetime);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;
    bool isAlive() const;

private:
    sf::Sprite sprite;
    sf::Vector2f velocity;
    float lifetime;
};

#endif // PARTICLE_H