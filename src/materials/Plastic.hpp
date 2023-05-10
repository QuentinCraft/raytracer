/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** plastic.h
*/

#ifndef RAYTRACER_PLASTIC_HPP
#define RAYTRACER_PLASTIC_HPP

#include "AMaterial.hpp"

namespace RayTracer {

    class Plastic : public AMaterial {
        public:
            Plastic() : AMaterial() {
                _diffuse = {0.5, 0.5, 0.5};
                _specular = {0.7, 0.6, 0.6};
                _shininess = 0.25 * 128;
                _reflection = false;
                _refraction = 0;
            }
    };

} // RayTracer

#endif //RAYTRACER_PLASTIC_HPP
