#include "Ship.h"

Ship::Ship(std::string fname, sf::Vector2u size){

  if(!ship.loadFromFile(fname)){
    std::cerr << "Failed to load a file" << std::endl;
    
  }
  ship.setSmooth(true);
  shipSprite.setTexture(ship);
  x = size.x/2u;
  y = size.y/2u;
  sf::Vector2f playerPos(x,y);
  shipSprite.setPosition(playerPos);
  shipSprite.setOrigin(shipWidth / 2.0f, shipLength / 2.0f);
}
void Ship::update(sf::Event event, sf::Vector2u wsize, float deltaTime) {
    // Get rotation and direction vectors
    float rotation = shipSprite.getRotation();
    float rotationRad = rotation * (3.14159265f / 180.0f);
    sf::Vector2f forwardDirection(std::cos(rotationRad - 3.14159265f / 2), std::sin(rotationRad - 3.14159265f / 2));
    sf::Vector2f rightDirection(-forwardDirection.y, forwardDirection.x);

    // Handle input
    handleKeyPress(event, rotationRad, forwardDirection, rightDirection);

    // Update particles
    updateParticles(deltaTime);

    // Apply acceleration and friction
    if (abs(velocity.x) <= VMAXv.x && abs(velocity.y) <= VMAXv.y) {
        velocity += acceleration;
    }
    FRICTIONF = FRICTION_COEF * velocity;
    velocity -= FRICTIONF;

    // Update position
    x += velocity.x;
    y += velocity.y;
    shipSprite.setPosition(x, y);

    // Handle collision
    handleCollision(wsize);
}

void Ship::draw(sf::RenderWindow &window) {
    for (auto &particle : particles) {
        particle.draw(window);
    }
    window.draw(shipSprite);
}

void Ship::handleKeyPress(sf::Event event, float rotationRad, sf::Vector2f forwardDirection, sf::Vector2f rightDirection) {
    if (event.type != sf::Event::KeyPressed) return;

    float halfShipWidth = shipWidth / 2.0f;
    float halfShipLength = shipLength / 2.0f;

    // W or Up key for forward movement
    if (sf::Keyboard::Key::W == event.key.code || sf::Keyboard::Key::Up == event.key.code) {
        acceleration += forwardDirection * dAcc;
        sf::Vector2f particlePosition = shipSprite.getPosition() - forwardDirection * halfShipLength;
        particles.push_back(Particle(particlePosition, -forwardDirection * PARTICLE_SPEED, PARTICLE_LIFETIME));
    }

    // A or Left key for rotation and side thrusters
    if (sf::Keyboard::Key::A == event.key.code || sf::Keyboard::Key::Left == event.key.code) {
        acceleration -= rightDirection * dAcc;
        shipSprite.rotate(-ROTATION_RATE);
        sf::Vector2f particlePosition = shipSprite.getPosition() + rightDirection * halfShipWidth;
        particles.push_back(Particle(particlePosition, rightDirection * PARTICLE_SPEED, PARTICLE_LIFETIME));
    }

    // S or Down key for reverse thrust
    if (sf::Keyboard::Key::S == event.key.code || sf::Keyboard::Key::Down == event.key.code) {
        acceleration -= forwardDirection * dAcc;
        sf::Vector2f particlePosition = shipSprite.getPosition() + forwardDirection * halfShipLength;
        particles.push_back(Particle(particlePosition, forwardDirection * PARTICLE_SPEED, PARTICLE_LIFETIME));
    }

    // D or Right key for rotation and side thrusters
    if (sf::Keyboard::Key::D == event.key.code || sf::Keyboard::Key::Right == event.key.code) {
        acceleration += rightDirection * dAcc;
        shipSprite.rotate(ROTATION_RATE);
        sf::Vector2f particlePosition = shipSprite.getPosition() - rightDirection * halfShipWidth;
        particles.push_back(Particle(particlePosition, -rightDirection * PARTICLE_SPEED, PARTICLE_LIFETIME));
    }

    // Limit rotation
    if (shipSprite.getRotation() >= ROTATION_LIMIT) {
        shipSprite.setRotation(ROTATION_LIMIT);
    }
    if (shipSprite.getRotation() <= -ROTATION_LIMIT) {
        shipSprite.setRotation(-ROTATION_LIMIT);
    }
}

void Ship::handleCollision(sf::Vector2u wsize) {
    sf::Vector2f reset = sf::Vector2f(x, y);

    if (x <= 0) {
        x = 0;
        reset = sf::Vector2f(x, y);
        velocity.x *= -3;
        acceleration.x = 0;
        shipSprite.setPosition(reset);
    } else if (x >= wsize.x - shipWidth) {
        x = wsize.x - shipWidth;
        reset = sf::Vector2f(x, y);
        velocity.x *= -3;
        acceleration.x = 0;
        shipSprite.setPosition(reset);
    }

    if (y <= 0) {
        y = 0;
        reset = sf::Vector2f(x, y);
        velocity.y *= -3;
        acceleration.y = 0;
        shipSprite.setPosition(reset);
    } else if (y >= wsize.y - shipLength) {
        y = wsize.y - shipLength;
        reset = sf::Vector2f(x, y);
        velocity.y *= -3;
        acceleration.y = 0;
        shipSprite.setPosition(reset);
    }
}

void Ship::updateParticles(float deltaTime) {
    for (auto it = particles.begin(); it != particles.end();) {
        it->update(deltaTime);
        if (!it->isAlive()) {
            it = particles.erase(it);
        } else {
            ++it;
        }
    }
}

sf::Vector2f const Ship::getShipPos() {
    return shipSprite.getPosition();
}

sf::Sprite const Ship::getShipSprite() {
    return shipSprite;
}