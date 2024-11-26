#include "Manager.h"

int main() {
    sf::Vector2u windowSize(600, 600);
    Manager manager;
    manager.startApplication(windowSize);
    return 0;
}