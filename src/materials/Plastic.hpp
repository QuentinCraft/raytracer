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
            Plastic() : AMaterial(
                "plastic",
                {0.5, 0.5, 0.5},
                {0.7, 0.6, 0.6},
                0.25 * 128,
                0,
                false,
                0.0001
            ) {_name = "plastic";}
    };

} // RayTracer

#endif //RAYTRACER_PLASTIC_HPP
