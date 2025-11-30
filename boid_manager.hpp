#pragma once
#include "SFML/Graphics.hpp"
#include "boid.hpp"
#include <SFML/System/Vector2.hpp>
#include <sys/types.h>
#include <vector>

class boid_manager {
    public:
        boid_manager(u_int8_t count);
        ~boid_manager();

        void spawn_boids(u_int8_t count);
        // boids move away from others
        void seperation();
        // boids attempt to match the velocities of their neighbors
        // boids move toward the center of mass of their neighbors
        void cohesion();
        void update_velocity();
        void alignment();
        void update();

    private:
        std::vector<boid> boids;
        float avoid_factor = 1.0f;
        float min_velo = 0.f;
        float max_velo = 5.f;
};
