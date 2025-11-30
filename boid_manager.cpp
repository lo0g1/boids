#include "boid_manager.hpp"
#include <SFML/System/Vector2.hpp>
#include <chrono>
#include <iostream>
#include <random>
#include <sys/types.h>
#include <system_error>

unsigned int SCREEN_HEIGHT = 1080;
unsigned int SCREEN_WIDTH = 1080;

// add later a option to define params for locations
boid_manager::boid_manager(u_int8_t count) {
    if (!count) {
        return;
    }
    spawn_boids(count);
}

void boid_manager::seperation() {
    // iterate over every boid and if it's in the radius move away
    for (boid &b : boids) {
        // grab pos of a boid
        sf::Vector2f b1_pos = b.get_pos();

        for (auto &b2 : boids) {
            // if our position grabbed is equal to the boid in the vector move
            if (&b == &b2) {
                continue;
            }

            sf::Vector2f b2_pos = b2.get_pos();

            sf::Vector2f close_pos = b2_pos - b1_pos;
            b.m_velocity += close_pos * avoid_factor;
        }
    }
}

void boid_manager::alignment() {

    u_int8_t neighboring_boids = 0;

    sf::Vector2f vel_avg(0, 0);

    for (boid &b1 : boids) {

        for (boid &b2 : boids) {
            if (&b1 == &b2)
                continue;

            // if (dist < boid_dist) {
            //
            //     vel_avg += b2.m_velocity;
            //     neighboring_boids++;
            // }
        }
    }
}

void boid_manager::cohesion() {}

void boid_manager::update() {
    seperation();
    alignment();
    cohesion();
    for (auto &b : boids) {
        b.update();
    }
}

void boid_manager::spawn_boids(u_int8_t count) {

    std::default_random_engine generator;

    std::uniform_int_distribution<unsigned int> xpos_distr(1, SCREEN_WIDTH);
    std::uniform_int_distribution<unsigned int> ypos_distr(1, SCREEN_HEIGHT);
    std::uniform_int_distribution<int> velo_distr(min_velo, max_velo);

    for (int i = 0; i < count; i++) {

        boids.push_back( // fill our vector with boids with different
                         // velocity and positions
            boid(sf::Vector2f(xpos_distr(generator), ypos_distr(generator)),
                 sf::Vector2f(velo_distr(generator), velo_distr(generator))));
    }
}
