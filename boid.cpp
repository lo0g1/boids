#include "boid.hpp"
#include <SFML/System/Vector2.hpp>

boid::boid(sf::Vector2f position, sf::Vector2f velocity)
    : m_position(position),
      m_velocity(velocity) {}

boid::~boid() {}

sf::Vector2f boid::get_pos() { return this->m_position; }

sf::Vector2f boid::get_velo() { return this->m_velocity; }

void boid::set_velo(sf::Vector2f velocity) { this->m_velocity = velocity; }

void boid::set_pos(sf::Vector2f position) { this->m_position = position; }

void boid::update() {
    update_velocity();
    update_shape();
}

void boid::update_velocity() { this->m_position += m_velocity; }

void boid::update_shape() { m_shape.setPosition(this->m_position); }
