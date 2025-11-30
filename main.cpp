// #include "boid.cpp"
// #include "boid_manager.cpp"
// #include "boid_manager.hpp"
#include "SFML/Graphics.hpp"
#include <SFML/Window/Event.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({1080, 1080}), "Boid Implement");
    window.setFramerateLimit(144);
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
            }
        }
    }

    return 0;
}
