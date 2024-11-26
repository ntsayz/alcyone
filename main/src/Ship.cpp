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

void Ship::draw(sf::RenderWindow &window) {
    // Draw particles
    for (auto &particle : particles) {
      particle.draw(window);
    }
    // Draw the ship
    window.draw(shipSprite);
}
void Ship::update(sf::Event event, sf::Vector2u wsize, float deltaTime) {
    // Handle input and emit particles
    if (event.type == sf::Event::KeyPressed) {
        // Get ship's rotation in radians
        float rotation = shipSprite.getRotation();
        float rotationRad = rotation * (3.14159265f / 180.0f);

        // Calculate direction vectors
        sf::Vector2f forwardDirection(std::cos(rotationRad - 3.14159265f / 2), std::sin(rotationRad - 3.14159265f / 2));
        sf::Vector2f rightDirection(-forwardDirection.y, forwardDirection.x);

        // Calculate half dimensions as floats
        float halfShipWidth = static_cast<float>(shipWidth) / 2.0f;
        float halfShipLength = static_cast<float>(shipLength) / 2.0f;

        // set acceleration and emit particles
        if (sf::Keyboard::Key::W == event.key.code || sf::Keyboard::Key::Up == event.key.code) {
            acceleration += forwardDirection * dAcc;

            // Emit particle from rear
            sf::Vector2f particlePosition = shipSprite.getPosition() - forwardDirection * halfShipLength;
            sf::Vector2f particleVelocity = -forwardDirection * PARTICLE_SPEED;
            particles.push_back(Particle(particlePosition, particleVelocity, PARTICLE_LIFETIME));
        }
        if (sf::Keyboard::Key::A == event.key.code || sf::Keyboard::Key::Left == event.key.code) {
            acceleration -= rightDirection * dAcc;
            shipSprite.rotate(-ROTATION_RATE);

            // Emit particle from right side
            sf::Vector2f particlePosition = shipSprite.getPosition() + rightDirection * halfShipWidth;
            sf::Vector2f particleVelocity = rightDirection * PARTICLE_SPEED;
            particles.push_back(Particle(particlePosition, particleVelocity, PARTICLE_LIFETIME));
        }
        if (sf::Keyboard::Key::S == event.key.code || sf::Keyboard::Key::Down == event.key.code) {
            acceleration -= forwardDirection * dAcc;

            // Emit particle from front
            sf::Vector2f particlePosition = shipSprite.getPosition() + forwardDirection * halfShipLength;
            sf::Vector2f particleVelocity = forwardDirection * PARTICLE_SPEED;
            particles.push_back(Particle(particlePosition, particleVelocity, PARTICLE_LIFETIME));
        }
        if (sf::Keyboard::Key::D == event.key.code || sf::Keyboard::Key::Right == event.key.code) {
            acceleration += rightDirection * dAcc;
            shipSprite.rotate(ROTATION_RATE);

            // Emit particle from left side
            sf::Vector2f particlePosition = shipSprite.getPosition() - rightDirection * halfShipWidth;
            sf::Vector2f particleVelocity = -rightDirection * PARTICLE_SPEED;
            particles.push_back(Particle(particlePosition, particleVelocity, PARTICLE_LIFETIME));
        }

        // limit rotation
        if (shipSprite.getRotation() >= ROTATION_LIMIT)
            shipSprite.setRotation(ROTATION_LIMIT);
        if (shipSprite.getRotation() <= -ROTATION_LIMIT)
            shipSprite.setRotation(-ROTATION_LIMIT);
    }

    // Update particles
    updateParticles(deltaTime);

    // Collision with window bounds
    // (The collision logic remains the same as your original code)
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

    // Updating velocity with acceleration and friction
    if (abs(velocity.x) <= VMAXv.x && abs(velocity.y) <= VMAXv.y) {
        velocity += acceleration;
    }
    FRICTIONF = FRICTION_COEF * velocity;
    velocity -= FRICTIONF;

    // Update position through velocity
    x += velocity.x;
    y += velocity.y;

    shipSprite.setPosition(x, y);
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



void Ship::lookAtMouse(sf::RenderWindow &window){
    sf::Vector2f curPos = shipSprite.getPosition();
    sf::Vector2i position = sf::Mouse::getPosition(window);

    // now we have both the sprite position and the cursor
    // position lets do the calculation so our sprite will
    // face the position of the mouse
    const float PI = 3.14159265;

    float dx = curPos.x - position.x;
    float dy = curPos.y - position.y;

    float rotation = (atan2(dy, dx)) * 180u / PI;

    shipSprite.setRotation(rotation + 180u);

}

sf::Vector2f const Ship::getShipPos(){
    return shipSprite.getPosition();
}
sf::Sprite const Ship::getShipSprite(){
  return shipSprite;
}