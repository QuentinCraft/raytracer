/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Emerald.hpp
*/

#ifndef RAYTRACER_EMERALD_HPP
#define RAYTRACER_EMERALD_HPP

#include "AMaterial.hpp"

namespace RayTracer {

    class Emerald : public AMaterial {
    public:
        Emerald() : AMaterial(
                "emerald",
                {0.0215, 0.1745, 0.0215},
                {0.07568, 0.61424, 0.07568},
                {0.633, 0.727811, 0.633},
                76.8,
                1.57,
                false,
                0.0
        ) {_name = "emerald";}
    };

} // RayTracer

#endif //RAYTRACER_EMERALD_HPP
