#include "Ship.h"

Ship::Ship(const std::string& filename, const sf::Vector2u& windowSize)
    : position(windowSize.x / 2.0f, windowSize.y / 2.0f),
      velocity(0.0f, 0.0f),
      acceleration(0.0f, 0.0f),
      rotationSpeed(100.0f),
      maxSpeed(300.0f),
      accelerationRate(600.0f),
      frictionCoefficient(5.0f) {
    if (!shipTexture.loadFromFile(filename)) {
        std::cerr << "Failed to load file: " << filename << std::endl;
    }
    shipTexture.setSmooth(true);
    shipSprite.setTexture(shipTexture);
    shipSprite.setOrigin(shipTexture.getSize().x / 2.0f, shipTexture.getSize().y / 2.0f);
    shipSprite.setPosition(position);
}

void Ship::handleInput() {
    acceleration = sf::Vector2f(0.0f, 0.0f);

    // Movement input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        acceleration.y -= accelerationRate;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        acceleration.y += accelerationRate;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        acceleration.x -= accelerationRate;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        acceleration.x += accelerationRate;
    }

    // Rotation input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        shipSprite.rotate(-rotationSpeed * 0.016f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        shipSprite.rotate(rotationSpeed * 0.016f);
    }
}

void Ship::update(float deltaTime, const sf::Vector2u& windowSize) {
    // Update velocity with acceleration
    velocity += acceleration * deltaTime;

    // Apply friction to slow down the ship when no input is given
    if (velocity.x != 0.0f || velocity.y != 0.0f) {
        sf::Vector2f friction = velocity * frictionCoefficient * deltaTime;
        if (std::abs(friction.x) > std::abs(velocity.x))
            velocity.x = 0.0f;
        else
            velocity.x -= friction.x;

        if (std::abs(friction.y) > std::abs(velocity.y))
            velocity.y = 0.0f;
        else
            velocity.y -= friction.y;
    }

    // Limit speed to maxSpeed
    float speed = std::hypot(velocity.x, velocity.y);
    if(speed > maxSpeed) {
        velocity *= maxSpeed / speed;
    }

    // Update position
    position += velocity * deltaTime;

    // Collision detection with window bounds
    sf::FloatRect bounds = shipSprite.getGlobalBounds();
    if (position.x - bounds.width / 2 < 0) {
        position.x = bounds.width / 2;
        velocity.x = -velocity.x * 0.5f; // Bounce back with damping
    } else if (position.x + bounds.width / 2 > windowSize.x) {
        position.x = windowSize.x - bounds.width / 2;
        velocity.x = -velocity.x * 0.5f;
    }
    if (position.y - bounds.height / 2 < 0) {
        position.y = bounds.height / 2;
        velocity.y = -velocity.y * 0.5f;
    } else if (position.y + bounds.height / 2 > windowSize.y) {
        position.y = windowSize.y - bounds.height / 2;
        velocity.y = -velocity.y * 0.5f;
    }

    // Update sprite position
    shipSprite.setPosition(position);
}

void Ship::draw(sf::RenderWindow& window) {
    window.draw(shipSprite);
}

sf::Vector2f Ship::getPosition() const {
    return position;
}

const sf::Sprite& Ship::getSprite() const {
    return shipSprite;
}