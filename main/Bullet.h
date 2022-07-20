#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <string.h>
class Bullet{
    private:
        sf::Texture bulletTexture_;
        sf::Sprite bulletSprite_;
        sf::Vector2f acceleration, velocity;
    public:
        Bullet(std::string fname);

        sf::Sprite draw();
};


#endif