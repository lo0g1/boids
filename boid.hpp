#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstddef>

class boid {
    public:
        boid(sf::Vector2f position, sf::Vector2f velocity);
        ~boid();

        void set_velo(sf::Vector2f velocity);
        sf::Vector2f get_velo();

        sf::Vector2f get_pos();
        void set_pos(sf::Vector2f position);

        sf::Vector2f get_rotation();
        void set_orientation(float rotation);

        void update();

        void update_shape();

        void update_velocity();

    private:
        sf::CircleShape m_shape;
        sf::Vector2f m_position;
        sf::Vector2f m_velocity;
        float m_orientation;
        friend class boid_manager;
};
